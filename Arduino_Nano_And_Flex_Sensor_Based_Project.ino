//Prateek
//wwww.prateeks.in
//https://www.youtube.com/c/JustDoElectronics/videos

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

int flexs = A0; 
int flexdata = 0;
int yellow = 5;
int blue = 4;
int buzzer = 3; 
void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Welcome");
  pinMode(flexs, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop()
{
  flexdata = analogRead(flexs);
  Serial.print("flex value;");
  Serial.print(flexdata);
  Serial.println("");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Welcome To Our ");
  lcd.setCursor(0, 1);
  lcd.print("     Project     ");
  digitalWrite(yellow, LOW);
  digitalWrite(blue, LOW);
  
  if ( flexdata < 690)
  {
    analogWrite(buzzer, 150);
    digitalWrite(yellow, HIGH);
    digitalWrite(blue, LOW);
    lcd.clear();
    lcd.print("Give Me Medicine");
    Serial.print("Give Me Medicine");
  }

  if ( flexdata > 850)
  {
    analogWrite(buzzer, 0);
    digitalWrite(yellow, LOW);
    digitalWrite(blue, HIGH);
    lcd.clear();
    lcd.print("Give Me Water");
    Serial.print("Give Me Water");
  }
   if ( flexdata >= 900)
  {
    analogWrite(buzzer, 0);
    digitalWrite(yellow, LOW);
    digitalWrite(blue, LOW);
    lcd.clear();
    lcd.print("Give Me Milk");
    Serial.print("Give Me Milk");
  }

  delay(1000);

}
