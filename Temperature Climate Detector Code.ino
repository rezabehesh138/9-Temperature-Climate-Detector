int red = 8;
int green = 9;
#include <LiquidCrystal.h> // include the library code
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  Serial.begin(9600); //setup serial
  lcd.begin(16, 2);
}

void loop() {
  float voltage = analogRead(A0);  //read the inpute voltage (analog pin A0)
  float temp = voltage * (0.48828125); //computing Temp
  lcd.setCursor(0, 0);
  lcd.print("Temp = "); //show Temp
  lcd.print(temp); //show Temp
  //  lcd.print("\xC2\xB0"); //show Temp
  lcd.print("*C"); //show Temp
  // delay(2000); //waits for 2 second

  if (temp > 32) {
    digitalWrite(red , HIGH);
    digitalWrite(green , LOW);
    lcd.setCursor(0, 1);
    lcd.print("WARM"); //show Temp
    

  }

  else {
    digitalWrite(green , HIGH);
    digitalWrite(red , LOW);
    lcd.setCursor(0, 1);
    lcd.print("COLD"); //show Temp
  }
  delay(2000);
  lcd.clear();

}

