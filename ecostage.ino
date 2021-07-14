#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
#include "DHT.h" 
#define DHTPIN A0 
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE); 
int analogMQ7 = A1;
int analogMQ4 = A2;
int led1=8;
int led2=7;
byte degree[8] = 
{ 
B00111, 
B00101, 
B00111, 
B00000, 
B00000, 
B00000, 
B00000, 
}; 
LiquidCrystal_I2C lcd(0x27,16,2); 
void setup() { 

pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
lcd.init(); 
lcd.backlight(); 
lcd.createChar(1, degree); 
Serial.begin(9600); 
dht.begin(); 
} 
void loop() { 
delay(2000); 
float h = dht.readHumidity(); 
float t = dht.readTemperature(); 
float val1 = analogRead(analogMQ7);
float val2 = analogRead(analogMQ4);
  if(val1>510 || val2>300)
  {
    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);
  }
  else if(val1<510 || val2<300)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }
  lcd.setCursor(0, 0);
  lcd.print("Hum:           %");
  lcd.setCursor(11, 0);
  lcd.print(h);
  lcd.setCursor(0, 1);
  lcd.print("temp:           1C");
  lcd.setCursor(11, 1);
  lcd.print(t);
  delay(2000);

  lcd.setCursor(0, 0);
  lcd.print("CO:              %");
  lcd.setCursor(11, 0);
  lcd.print(val1);
  lcd.setCursor(0, 1);
  lcd.print("MH:        ");
  lcd.print(val2);
  lcd.setCursor(11, 1);

  delay(3000);

  

}
