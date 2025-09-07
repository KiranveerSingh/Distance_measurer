# 📏 Ultrasonic Distance Measurer

## 📌 Project Overview
This project is an **ultrasonic distance calculator** that uses an **Arduino Uno** and an **HC-SR04 ultrasonic sensor** to measure the distance to an object. The measured distance is then displayed on a single **7-segment display**. This project is a foundational example of using sensors and displays in an embedded system.

## 🛠️ Features
- Accurate distance measurement using ultrasound
- Real-time display on a single 7-segment display
- Simple, low-cost hardware setup
- Battery-powered for portability (using a 9V battery)

## 🎯 Use Cases
- Simple range finder
- DIY robotics obstacle detection
- Educational tool for learning about sensors and displays
- Personal projects and prototyping

## 🧩 Components Used

| Component                             | Role                                                             |
|--------------------------------------|------------------------------------------------------------------|
| Arduino Uno                          | The microcontroller that processes data and controls output        |
| HC-SR04 Ultrasonic Sensor            | Measures distance using sound waves                             |
| Single-Digit 7-Segment Display       | Displays the last digit of the measured distance                   |
| 9V Battery                           | Provides portable power for the Arduino                            |
| Resistors (220-330Ω)                 | Current-limiting resistors for the 7-segment display              |
| Jumper Wires                         | Connects all components on the breadboard                        |

## ⚙️ Working Principle
1. The **Arduino** sends a trigger pulse to the **HC-SR04 sensor**.
2. The sensor emits an ultrasonic sound wave and waits for the echo.
3. It measures the time taken for the echo to return to the sensor.
4. The Arduino uses the speed of sound to calculate the **distance**.
5. The last digit of the calculated distance is then displayed on the **7-segment display**.

## 💡 Future Scope
- Add a multi-digit display for more accurate readings
- Integrate a buzzer for audible alerts at specific distances
- Use a servo motor to scan a wider area for objects
- Implement an OLED display for showing both distance and unit (cm/inches)

## 📁 File Structure
Distance-measurer/
│── ArduinoIDE-Code/
│   └── Measuring code.ino
│── Images/
│   ├── circuit diagram.png
│   └── project.jpg
│── How-I-Made-It.md
│── LICENSE
│── README.md


## ✅ How to Use
1. Clone the repository to your local machine.
2. Open the `Measuring_code.ino` file in the Arduino IDE.
3. Upload the sketch to your Arduino Uno board.
4. Connect the components as shown in the circuit diagram.
5. Point the sensor at an object to see the distance displayed.


## 📄 License
This project is open-source under the [MIT License](LICENSE).

---

**Built by [Kiranveer Singh]**