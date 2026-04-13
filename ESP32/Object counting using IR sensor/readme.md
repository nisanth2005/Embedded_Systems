                                                **ESP32 IR Object Counting System using I2C LCD**

**1. Description**
This project demonstrates how to build an object counting system using an ESP32, an IR sensor, and a 16x2 LCD display with I2C communication. The IR sensor detects objects passing in front of it, and the ESP32 increments the count accordingly. The count value is displayed in real-time on the LCD screen.

---

**2. Components Required**
ESP32 (WROOM module)
IR Sensor module
16x2 LCD display
I2C LCD backpack module (PCF8574)
Jumper wires
Breadboard (optional)

---

**3. Circuit Connections**
Refer circuit diagram which is in the folder

---

**4. Software Requirements**
Arduino IDE
ESP32 Board Package installed
LiquidCrystal_I2C library
Wire library (comes with Arduino)

---

**5. Working**
The IR sensor detects the presence of an object by emitting infrared light and sensing its reflection. When an object passes in front of the sensor, the output signal changes state. The ESP32 reads this signal and increments the object count.

The ESP32 communicates with the LCD using the I2C protocol, which uses only two wires (SDA and SCL). The updated count value is continuously displayed on the LCD screen.

---

**6. Code**
Refer code which is in the folder

---

**7. Output**
Refer output image which is in the folder

---

**8. Learning Outcomes**
Understanding IR sensor working principle
Interfacing sensors with ESP32
Using I2C communication with LCD
Real-time data display using microcontroller
Basic event detection and counting logic

---

**9. Notes**
Ensure correct I2C address (commonly 0x27 or 0x3F)
Adjust the potentiometer on the LCD module for proper contrast
Verify proper IR sensor alignment and sensitivity
Avoid multiple counts by adding delay (debounce logic)

---

**10. Future Improvements**
Add buzzer indication for object detection
Store count using EEPROM (retain after power off)
Integrate WiFi to send data to cloud
Use multiple sensors for directional counting

---

**11. Applications**
Industrial object counting systems
People counting systems
Conveyor belt monitoring
Smart inventory systems
