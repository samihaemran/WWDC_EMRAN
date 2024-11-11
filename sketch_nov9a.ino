#include <Arduino.h>  // Include the Arduino library for basic functions

// Define pin numbers for each component
const int sensorPin = A0;        // MQ2 analog output connected to analog pin A0
const int greenLEDPin = 13;      // Green LED for low smoke levels
const int blueLEDPin = 4;        // Blue LED for moderate smoke levels
const int redLEDPin = 2;         // Red LED for high smoke levels
const int buzzerPin = 9;         // Buzzer for alarm notification

// Threshold levels for smoke density (in analog values)
// These values are the thresholds at which the smoke levels change the state of the LEDs and buzzer.
const int smokeThresholdGreen = 50;    // Minimum level for Green LED (0 - 50, represents safe air quality)
const int smokeThresholdBlue = 250;    // Minimum level for Blue LED (51 - 250, represents moderate smoke levels)
const int smokeThresholdRed = 251;    // Minimum level for Red LED and buzzer (251+, represents high smoke levels)

void setup() {
  // The setup function runs once when the program starts.
  // It is used to initialise settings, configure pins, and set up serial communication or any other setup tasks.
  
  // Set each LED and buzzer pin as output for controlling their states
  pinMode(greenLEDPin, OUTPUT);   // Configure Green LED pin as output
  pinMode(blueLEDPin, OUTPUT);    // Configure Blue LED pin as output
  pinMode(redLEDPin, OUTPUT);     // Configure Red LED pin as output
  pinMode(buzzerPin, OUTPUT);     // Configure buzzer pin as output

  // Configure the sensor pin as input to read smoke levels from the MQ2 sensor
  pinMode(sensorPin, INPUT);

  // Initialise serial communication for monitoring values in Serial Monitor
  // This allows us to observe the smoke level readings in real time
  Serial.begin(9600);
}

void loop() {
  // Read the analog smoke level from the MQ2 sensor
  // The sensor reads values based on smoke density in the air. The higher the smoke density, 
  // the higher the value returned by analogRead().
  int smokeLevel = analogRead(sensorPin);

  // Print the smoke level to the Serial Monitor for debugging purposes
  // This will help us see the raw value coming from the sensor
  Serial.print("Smoke Level: ");
  Serial.println(smokeLevel);

  // Determine LED and buzzer states based on smoke level readings
  // This is where the decision-making occurs based on the threshold levels defined above

  if (smokeLevel >= smokeThresholdRed) {
    // If the smoke level is at or above the Red threshold (201 or more):
    // This indicates a dangerous smoke level, so we turn on the Red LED and activate the buzzer.
    // also turn off the other LEDs to avoid confusion.
    digitalWrite(redLEDPin, HIGH);        // Turn on Red LED to indicate high smoke level
    digitalWrite(blueLEDPin, LOW);        // Turn off Blue LED
    digitalWrite(greenLEDPin, LOW);       // Turn off Green LED
    tone(buzzerPin, 1000);                // Activate buzzer with 1000 Hz frequency to alert about danger
    Serial.println("Red LED and Buzzer ON (High smoke level)");
  } 
  else if (smokeLevel >= smokeThresholdBlue) {
    // If the smoke level is at or above the Blue threshold (51-200):
    // This indicates a moderate smoke level. The Blue LED will turn on to warn of moderate smoke, 
    // while the Green, Red LED, and buzzer are turned off.
    digitalWrite(redLEDPin, LOW);         // Turn off Red LED
    digitalWrite(blueLEDPin, HIGH);       // Turn on Blue LED to indicate moderate smoke level
    digitalWrite(greenLEDPin, LOW);       // Turn off Green LED
    noTone(buzzerPin);                    // Turn off buzzer as the smoke level is not yet dangerous
    Serial.println("Blue LED ON (Moderate smoke level)");
  }
  else if (smokeLevel < smokeThresholdGreen) {
    // If the smoke level is below the Green threshold (50 or less):
    // This indicates a safe air quality level, so the Green LED will be turned on.
    // The buzzer and other LEDs are turned off to indicate no issues.
    digitalWrite(redLEDPin, LOW);         // Turn off Red LED
    digitalWrite(blueLEDPin, LOW);        // Turn off Blue LED
    digitalWrite(greenLEDPin, HIGH);      // Turn on Green LED to indicate safe smoke level
    noTone(buzzerPin);                    // Turn off buzzer as air quality is safe
    Serial.println("Green LED ON (Low smoke level)");
  }
  else {
    // In case none of the above conditions are met, all LEDs and the buzzer will be turned off.
    // This case could represent very low smoke levels or the system not detecting smoke properly.
    digitalWrite(redLEDPin, LOW);         // Turn off Red LED
    digitalWrite(blueLEDPin, LOW);        // Turn off Blue LED
    digitalWrite(greenLEDPin, LOW);       // Turn off Green LED
    noTone(buzzerPin);                    // Turn off buzzer
    Serial.println("All LEDs and Buzzer OFF (Safe level)");
  }

  // Delay for 500ms before reading the sensor again, this helps avoid excessive readings and allows the system to stabilize
  delay(500); // Wait for 500 ms before repeating the loop for stability
}


