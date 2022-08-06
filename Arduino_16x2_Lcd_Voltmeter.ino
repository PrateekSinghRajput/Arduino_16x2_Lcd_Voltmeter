// Viral Science www.viralsciencecreativity.com www.youtube.com/c/viralscience
// Arduino OLED Voltmeter


#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,10,9,8,7);

int analogInput = A0;  //Sensor Input

void setup() {
  pinMode(analogInput, INPUT);
  Serial.begin(9600);
  Serial.println("VOLTMETER");
   lcd.begin(16,2);
  lcd.print("  Welcome To");
  lcd.setCursor(0, 1);
  lcd.print("JustDoElectronic");
  delay(3000);
  lcd.clear();
}

float vout = 0.0;
float vin = 0.0;

float R1 = 30000.0;
float R2 = 7500.0;

int value = 0;

void loop() {

  value = analogRead(analogInput);
  vout = (value * 5.0) / 1024.0;
  vin = vout / (R2 / (R1 + R2));

  Serial.print("INPUT Voltage= ");
  Serial.println(vin, 2);
  lcd.setCursor(0, 0);
  lcd.print("Voltage");
  lcd.setCursor(0, 1);
  lcd.print(vin);


  delay(1000);


}
