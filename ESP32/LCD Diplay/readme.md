                                                 ESP32 I2C LCD Display Project

 1. Description

This project demonstrates how to interface a 16x2 LCD display with an ESP32 using the I2C communication protocol. The ESP32 sends data to the LCD through an I2C module, and the messages  are displayed on the screen.

2. Components Required

* ESP32 (WROOM module)
* 16x2 LCD display
* I2C LCD backpack module (PCF8574)
* Jumper wires
* Breadboard (optional)

3. Circuit Connections

I2C LCD Pin                   	ESP32 Pin
VCC                              	5V
GND                             	GND
SDA	                             GPIO 21
SCL	                             GPIO 22

Refer to the circuit diagram provided in the folder.

4. Software Requirements

* Arduino IDE
* ESP32 Board Package installed
* LiquidCrystal_I2C library
* Wire library (comes with Arduino)

 5. Working

The ESP32 communicates with the LCD using the I2C protocol, which requires only two wires (SDA and SCL). The I2C backpack converts serial data into parallel signals required by the LCD. The ESP32 acts as the master device and sends commands and data to the LCD, which acts as the slave device.

 6. Code

Refer to the code provided in the folder.

 7. Output

Refer to the circuit diagram provided in the folder.

 8. Learning Outcomes

* Understanding I2C communication protocol
* Interfacing LCD with ESP32
* Reducing GPIO usage using I2C
* Basics of embedded system communication

9. Notes

* Ensure correct I2C address (commonly 0x27 or 0x3F)
* Adjust the potentiometer on the I2C module for proper display contrast
* Verify SDA and SCL connections

 10. Future Improvements

* Display sensor data (temperature, distance, etc.)
* Implement scrolling text
* Create menu-based interface using buttons

11. Applications

* Temperature display system
* Digital clock
* Motor speed display
* IoT data display
