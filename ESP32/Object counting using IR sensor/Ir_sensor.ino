#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define IR_PIN 14

// Try 0x27 first, if not working change to 0x3F
LiquidCrystal_I2C lcd(0x27, 16, 2);

int count = 0;
int lastState = HIGH;

void setup() {
  Serial.begin(115200);

  pinMode(IR_PIN, INPUT);

  // ESP32 I2C init (VERY IMPORTANT)
  Wire.begin(21, 22);

  // Proper LCD init for this library
  lcd.init();          // ✅ instead of begin()
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("System Ready");

  Serial.println("System Started");
}

void loop() {
  int currentState = digitalRead(IR_PIN);

  // Debug print
  Serial.println(currentState);

  // Detect object (falling edge)
  if (lastState == HIGH && currentState == LOW) {
    count++;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Count:");
    lcd.setCursor(0, 1);
    lcd.print(count);

    Serial.print("Count = ");
    Serial.println(count);

    delay(300); // debounce
  }

  lastState = currentState;
}