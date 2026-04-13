#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);

  lcd.init();
  lcd.backlight();

  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();
  float hum  = dht.readHumidity();

  if (!isnan(temp) && !isnan(hum)) {

    lcd.setCursor(0,0);
    lcd.print("Temp: ");
    lcd.print(temp);
    lcd.print((char)223); // degree symbol
    lcd.print("C   "); // spaces to clear old data

    lcd.setCursor(0,1);
    lcd.print("Hum : ");
    lcd.print(hum);
    lcd.print("%   ");

    Serial.print("Temp: ");
    Serial.print(temp);
    Serial.print(" C  Hum: ");
    Serial.println(hum);
  }

  delay(2000); // IMPORTANT for DHT11
}