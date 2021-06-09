#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int VRx = A0;
int VRy = A1;
int xPosition = 0;
int yPosition = 0;
int mapX = 0;
int mapY = 0;
int mapX2;
int p = 0;

void setup() {

  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);

}

void loop() {
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, -512, 512);

  Serial.print("X: ");
  Serial.print(mapX);
  Serial.print(" | Y: ");
  Serial.print(mapY);

  lcd.clear();
  lcd.setCursor(p, 0);
  lcd.print("test");
  if (mapX2 >= mapX) {
    p++;
  }
  mapX2 = mapX;
  delay(500);

}
