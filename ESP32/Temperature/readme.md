                                                         ESP32 I2C LCD Temperature & Humidity Monitoring Project
1. Description

This project demonstrates how to interface a 16x2 LCD display with an ESP32 using the I2C communication protocol and display real-time temperature and humidity data using a DHT11 sensor. The ESP32 reads environmental data from the sensor and continuously updates the values on the LCD screen.

2. Components Required

* ESP32 (WROOM module)
* 16x2 LCD display
* I2C LCD backpack module (PCF8574)
* DHT11 Temperature and Humidity Sensor
* Jumper wires
* Breadboard (optional)

3. Circuit Connections

Refer to the circuit diagram available in the project folder.

3.1 DHT11 Connections:

* VCC → 3.3V (ESP32)
* GND → GND
* DATA → GPIO 4

 3.2 LCD (I2C) Connections:

* VCC → 5V
* GND → GND
* SDA → GPIO 21
* SCL → GPIO 22

 4. Software Requirements

* Arduino IDE
* ESP32 Board Package installed
* DHT sensor library (Adafruit)
* Adafruit Unified Sensor library
* LiquidCrystal_I2C library
* Wire library (comes with Arduino)

5. Working

The ESP32 reads temperature and humidity data from the DHT11 sensor at regular intervals. The sensor sends digital data to the ESP32, which processes it and displays the values on the LCD via the I2C protocol.

The I2C communication reduces the number of GPIO pins required by using only two lines:

* SDA (Serial Data Line)
* SCL (Serial Clock Line)

The ESP32 acts as the master device, while the LCD (via I2C module) acts as the slave device. The displayed values are updated continuously, providing near real-time monitoring of environmental conditions.

6. Code

Refer to the code file available in the project folder.

7. Output

refer output  which is in the folder

8. Learning Outcomes

* Understanding I2C communication protocol
* Interfacing sensors with ESP32
* Displaying real-time data on LCD
* Reducing GPIO usage using I2C
* Basics of embedded system design

9. Notes

* Ensure correct I2C address (commonly 0x27 or 0x3F)
* Adjust the potentiometer on the I2C module for proper contrast
* Maintain a delay of ~2 seconds for stable DHT11 readings
* Verify all wiring connections before powering the circuit

10. Future Improvements

* Use DHT22 for higher accuracy
* Add buzzer alert for temperature threshold
* Send data to cloud platforms (IoT integration)
* Implement data logging
* Add graphical display or mobile app interface

11. Applications

* Temperature and humidity monitoring system
* Smart home environmental monitoring
* Industrial condition monitoring
* IoT-based weather station

