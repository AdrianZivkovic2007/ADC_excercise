/*
  Name: Adrian Zivkovic
  Datum: 25.05.2025
  Projekt: ADC_excercise
*/

#include <Arduino.h>

const int potPin = A0;  // Pin connected to the potentiometer

void setup() {
    Serial.begin(9600); // Start the serial communication
}

void loop() {
    int analogValue = analogRead(potPin); // Read raw analog value (0-1023)
    
    // Convert to voltage (0 - 5 V)
    float voltage = analogValue * (5.0 / 1023.0);

    // Print voltage with two decimal places
    Serial.print("Potentiometer analog value = ");
    Serial.print(voltage, 2); // 2 decimal places
    Serial.println(" V");

    delay(500); // Wait for 0.5 seconds
}
