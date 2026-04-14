#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define IR_PIN 14
#define DHTPIN 4
#define DHTTYPE DHT11
#define ECG_PIN 34

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);

int beatCount = 0;
unsigned long lastBeatTime = 0;
unsigned long lastCalcTime = 0;
float bpm = 0;

int threshold = 1500;   // 🔧 Adjust if needed

void setup() {
  Serial.begin(115200);

  pinMode(IR_PIN, INPUT);

  Wire.begin(21, 22);
  lcd.init();
  lcd.backlight();

  dht.begin();

  lcd.setCursor(0, 0);
  lcd.print("Health System");
  delay(2000);
  lcd.clear();
}

void loop() {

  int irState = digitalRead(IR_PIN);

  // 🟢 NO PATIENT
  if (irState == HIGH) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("No Patient");
    lcd.setCursor(0, 1);
    lcd.print("System Idle");

    bpm = 0;
    beatCount = 0;

    delay(500);
    return;
  }

  // 🟢 PATIENT DETECTED

  float temp = dht.readTemperature();

  // Handle DHT error
  if (isnan(temp)) {
    temp = 0;
  }

  int ecgValue = analogRead(ECG_PIN);

  // ❤️ ECG Peak Detection (Improved)
  if (ecgValue > threshold) {
    if (millis() - lastBeatTime > 300) {  // debounce
      beatCount++;
      lastBeatTime = millis();
    }
  }

  // ❤️ Calculate BPM every 5 seconds
  if (millis() - lastCalcTime > 5000) {
    bpm = beatCount * 12;   // 5 sec → BPM
    beatCount = 0;
    lastCalcTime = millis();
  }

  // 🧪 Debug (optional)
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" | ECG: ");
  Serial.print(ecgValue);
  Serial.print(" | BPM: ");
  Serial.println(bpm);

  // 📺 DISPLAY NORMAL DATA
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temp);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("BPM:");
  lcd.print((int)bpm);

  // 🔴 ALERT CONDITION (FIXED LOGIC)
  if ((temp > 38) || 
      ((bpm > 120 || bpm < 50) && bpm != 0)) {

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("!!! ALERT !!!");
    lcd.setCursor(0, 1);
    lcd.print("Check Patient");

    delay(2000);
  }

  delay(200);
}