📌 Description

This project implements a smart health monitoring system using an ESP32 microcontroller. It measures real-time body temperature, monitors heart activity, and detects patient presence. All parameters are displayed on a 16x2 LCD using I2C communication.

Key Highlights:

Real-time temperature monitoring
Heart rate estimation using ECG
Patient presence detection
Alert system for abnormal conditions
🧰 Components Required
ESP32 (WROOM module)
16x2 LCD display
I2C LCD backpack module (PCF8574)
DHT11 Temperature Sensor
AD8232 ECG Sensor Module
IR Sensor Module
Jumper wires
Breadboard (optional)
🔌 Circuit Connections

Refer to the circuit diagram available in the project folder.

3.1 DHT11 Connections
VCC → 3.3V (ESP32)
GND → GND
DATA → GPIO 4
3.2 LCD (I2C) Connections
VCC → 5V
GND → GND
SDA → GPIO 21
SCL → GPIO 22
3.3 IR Sensor Connections
VCC → 3.3V
GND → GND
OUT → GPIO 14
3.4 ECG (AD8232) Connections
3.3V → 3.3V (ESP32)
GND → GND
OUTPUT → GPIO 34

Electrode Placement:

RA → Right Arm / Right Chest
LA → Left Arm / Left Chest
RL → Right Leg / Lower Abdomen
💻 Software Requirements
Arduino IDE
ESP32 Board Package
DHT Sensor Library (Adafruit)
Adafruit Unified Sensor Library
LiquidCrystal_I2C Library
Wire Library
⚙️ Working

The system operates as follows:

IR sensor detects patient presence
If patient is detected:
Temperature is measured using DHT11
ECG signal is read and BPM is calculated
Values are displayed on LCD
If abnormal values are detected:
ALERT message is displayed

I2C Communication:

SDA → Data transfer
SCL → Clock signal
Reduces GPIO usage to only 2 pins
🧾 Code

Refer to the code file available in the project folder.

📊 Output

Refer to the output image available in the project folder.

🎯 Learning Outcomes
Multi-sensor interfacing with ESP32
Basics of ECG signal processing
I2C communication implementation
Real-time monitoring systems
Embedded system design and debugging
⚠️ Notes
Ensure correct I2C address (0x27 / 0x3F)
Adjust LCD contrast using potentiometer
Proper electrode placement is critical
Avoid movement during ECG measurement
Double-check all wiring before powering
🚀 Future Improvements
Add buzzer for alerts
Implement data logging
Improve ECG accuracy with filtering
Add wireless monitoring (WiFi)
Develop mobile/web interface
🏥 Applications
Patient monitoring systems
Biomedical instrumentation
Remote health monitoring
Educational healthcare projects
