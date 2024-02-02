#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHT_PIN 2 // Change this to the pin where your temperature sensor is connected

DHT dht(DHT_PIN, DHT11);
LiquidCrystal_I2C lcd(0x27, 16, 2); // Change the address (0x27) based on your I2C module

void setup() {
  lcd.begin(16, 2);
  dht.begin();
  lcd.init();
  lcd.clear();
}

void loop() {


  float temperature = dht.readTemperature();
  
  lcd.setCursor(0, 0);
  lcd.print("Temperature:");

  lcd.setCursor(0, 1);
  lcd.print(temperature);
  lcd.print(" C");
  
}
