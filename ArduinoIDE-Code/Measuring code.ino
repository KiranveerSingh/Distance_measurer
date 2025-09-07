// Define the pins for the HC-SR04 Ultrasonic Sensor
#define TRIGGER_PIN 9
#define ECHO_PIN 10

// Define the pins for the 7-Segment Display (Common Cathode)
// These pins correspond to segments a, b, c, d, e, f, g of the display.
const int a = 2;
const int b = 3;
const int c = 4;
const int d = 5;
const int e = 6;
const int f = 7;
const int g = 8;

// Create an array to map digits to segments.
// The array 'digit_segments' stores the states (HIGH or LOW)
// for each of the 7 segments (a, b, c, d, e, f, g) for each digit from 0 to 9.
// A '1' means the segment is ON, and a '0' means it is OFF.
const int digit_segments[10][7] = {
  // a, b, c, d, e, f, g
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

// This function takes a number and lights up the corresponding segments on the display.
void display_number(int number) {
  // Ensure the number is between 0 and 9.
  if (number < 0 || number > 9) {
    return;
  }

  // Turn on/off the appropriate segments based on the digit_segments array.
  digitalWrite(a, digit_segments[number][0]);
  digitalWrite(b, digit_segments[number][1]);
  digitalWrite(c, digit_segments[number][2]);
  digitalWrite(d, digit_segments[number][3]);
  digitalWrite(e, digit_segments[number][4]);
  digitalWrite(f, digit_segments[number][5]);
  digitalWrite(g, digit_segments[number][6]);
}

void setup() {
  // Initialize the serial communication for debugging purposes.
  Serial.begin(9600);

  // Set the pin modes for the ultrasonic sensor.
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Set the pin modes for the 7-segment display segments.
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
}

void loop() {
  // Variables to store the duration of the sound wave and the calculated distance.
  long duration;
  int distance_cm;

  // Clear the trigger pin to ensure a clean signal.
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);

  // Send a 10-microsecond high pulse to the trigger pin to start the measurement.
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  // Read the duration of the echo pulse.
  // The 'pulseIn' function measures the time the ECHO pin is HIGH.
  duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate the distance in centimeters.
  // The speed of sound is approximately 343 meters/second or 0.0343 cm/microsecond.
  // The duration is for a round trip (to the object and back), so we divide by 2.
  distance_cm = duration * 0.0343 / 2;

  // Print the distance to the Serial Monitor for debugging.
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  // Display the last digit of the distance on the 7-segment display.
  // The modulo operator (%) gives the remainder when 'distance_cm' is divided by 10.
  // This effectively extracts the last digit (e.g., 123 % 10 = 3).
  display_number(distance_cm % 10);

  // Pause for a short period before taking the next measurement.
  delay(250);
}