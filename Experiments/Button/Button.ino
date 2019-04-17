#include <rgb_lcd.h>
#include <stdio.h>

int buttonPin = 2;
rgb_lcd lcd;
int buttonPushedCount = 0;

void setup() {
  pinMode(buttonPin,INPUT);
  lcd.begin(16, 2);
  lcd.print("Push the button");
  lcd.setCursor(0,1);
  lcd.print("to change colors");
}

void loop() {
  if(digitalRead(buttonPin)) {
    lcd.setRGB(255, 0, 0);
  } else {
    lcd.setRGB(0, 0, 255);
  }
}
