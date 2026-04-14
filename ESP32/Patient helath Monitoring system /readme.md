                                          ESP32 Smart Health Monitoring System (ECG + Temperature + IR + LCD)

1. Description
This project demonstrates the implementation of a smart health monitoring system using an ESP32 microcontroller. The system measures real-time body temperature using a DHT11 sensor, monitors heart activity using an AD8232 ECG sensor, and detects patient presence using an IR sensor. All the collected data is displayed on a 16x2 LCD using the I2C communication protocol.

The system provides continuous monitoring and alerts in case of abnormal conditions, making it suitable for basic healthcare and biomedical applications.

2. Components Required
ESP32 (WROOM module)
16x2 LCD display
I2C LCD backpack module (PCF8574)
DHT11 Temperature Sensor
AD8232 ECG Sensor Module
IR Sensor Module
Jumper wires
Breadboard (optional)

3. Circuit Connections

3.1 DHT11 Connections:
VCC → 3.3V (ESP32)
GND → GND
DATA → GPIO 4

3.2 LCD (I2C) Connections:
VCC → 5V
GND → GND
SDA → GPIO 21
SCL → GPIO 22

3.3 IR Sensor Connections:
VCC → 3.3V
GND → GND
OUT → GPIO 14

3.4 ECG (AD8232) Connections:
3.3V → 3.3V (ESP32)
GND → GND
OUTPUT → GPIO 34

Electrode Placement:
RA → Right Arm / Right Chest
LA → Left Arm / Left Chest
RL → Right Leg / Lower Abdomen
Refer to the circuit diagram available in the project folder.

4. Software Requirements
Arduino IDE
ESP32 Board Package installed
DHT sensor library (Adafruit)
Adafruit Unified Sensor library
LiquidCrystal_I2C library
Wire library (comes with Arduino)

5. Working
The system operates by continuously monitoring the presence of a patient using an IR sensor. When a patient is detected, the ESP32 activates the monitoring process.

The DHT11 sensor measures body temperature, while the AD8232 ECG sensor captures heart signals. The ESP32 processes the ECG signal to estimate heart rate (BPM). All values are displayed on the LCD using the I2C communication protocol.

The I2C protocol reduces wiring complexity by using only two communication lines:

SDA (Serial Data Line)
SCL (Serial Clock Line)

The ESP32 acts as the master device, while the LCD acts as the slave device.

In case of abnormal temperature or heart rate, the system displays an alert message on the LCD.

6. Code
Refer to the code file available in the project folder.

7. Output
Refer output image available in the project folder.

8. Learning Outcomes
Understanding multi-sensor interfacing with ESP32
Basics of ECG signal acquisition and processing
Implementation of I2C communication
Real-time data monitoring and display
Embedded system integration and debugging

9. Notes
Ensure correct I2C address (commonly 0x27 or 0x3F)
Adjust LCD contrast using onboard potentiometer
Maintain proper electrode placement for accurate ECG readings
Avoid movement during ECG measurement to reduce noise
Verify all wiring connections before powering the system

10. Future Improvements
Add buzzer for emergency alert system
Integrate data logging functionality
Improve ECG signal filtering and accuracy
Add wireless monitoring using ESP8266/ESP32 WiFi
Develop mobile or web-based monitoring dashboard

11. Applications
Basic patient monitoring system
Biomedical instrumentation projects
Remote health monitoring prototype
Educational healthcare system demonstration
