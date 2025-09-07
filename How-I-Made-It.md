# 🔧 How I Made the Ultrasonic Distance Measurer

## 1. Gathering the Components
I started by gathering all the necessary parts, including:
- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- Single 7-Segment Display (Common Cathode)
- Breadboard
- Jumper Wires
- 220 Ohm Resistors
- 9V Battery and Connector

## 2. Assembling the Circuit
I followed the circuit diagram to assemble the components on the breadboard.
- I connected the HC-SR04's VCC and GND pins to the Arduino's 5V and GND.
- The sensor's Trig and Echo pins were connected to Arduino digital pins 9 and 10, respectively.
- For the 7-segment display, I connected its common cathode pin to the Arduino's GND.
- Each of the display's segment pins (a-g) was connected to an Arduino digital pin (2-8) through a 220 Ohm resistor to protect the LEDs.
- I powered the entire setup by connecting the 9V battery to the Arduino Uno's DC power jack.

## 3. Writing and Uploading the Code
- I wrote the Arduino code in the IDE, defining the pins for both the sensor and the display.
- The code calculates the distance from the sensor data and uses a lookup table to display the last digit on the 7-segment display.
- After verifying the connections and code, I uploaded the sketch to the Arduino Uno.

## 4. Testing the Project
- Once the code was uploaded, the project began to work automatically.
- I pointed the sensor at different objects to see the corresponding single-digit distance displayed on the 7-segment display. The Serial Monitor helped me confirm the full distance reading for debugging.