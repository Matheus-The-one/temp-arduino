#include <LiquidCrystal.h>

// Pin configuration for the LCD
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// Analog pin for the LM35
const int analogPin = A0;

void setup() {
  lcd.begin(16, 2);  // Initialize the LCD with 16 columns and 2 rows
  lcd.print("Temp:");

  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  // Read the analog value from the LM35
  int sensorValue = analogRead(analogPin);

  // Convert the analog value to Celsius temperature
  float temperature = (sensorValue * 5.0 / 1024.0) * 100.0;

  // Display the temperature on the LCD
  lcd.setCursor(6, 0);
  lcd.print(temperature, 1);  // Display one decimal place

  // Print the temperature to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" degrees Celsius");

  delay(1000);  // Wait for a short delay before taking the next reading
}