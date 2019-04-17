#include <rgb_lcd.h>
#include <stdio.h>

int buttonPin = 2;
int buzzerPin = 3;
int tempPin = 3;
rgb_lcd lcd;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  lcd.begin(16, 2);
  lcd.setRGB(0, 0, 255);
  lcd.print("Push the button");
  lcd.setCursor(0, 1);
  lcd.print("to see temp");
}

void loop() {
  if (digitalRead(buttonPin)) {
    float temp = getTemp();
    writeTemp(temp);
    if (temp > 25.0) {
      digitalWrite(buzzerPin, HIGH);
    } else {
      digitalWrite(buzzerPin, LOW);
    }
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Push the button");
    lcd.setCursor(0, 1);
    lcd.print("to see temp");
  }
}

float getTemp() {
  float temp = analogRead(tempPin);
  temp = (float)(1023 - temp) * 10000 / temp;
  return 1 / (log(temp / 10000) / 3975 + 1 / 298.15) - 273.15;
}

void writeTemp(float temp) {
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temp, 2);
    lcd.print("      ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
}
