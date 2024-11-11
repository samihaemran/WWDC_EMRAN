# WWDC_EMRAN
Smoke Guard
Smoke Guard is an Arduino-powered smoke detection system designed to give real-time alerts on air quality and smoke presence using visual and audible signals. Inspired by my experience during a nearby bushfire—when I realised the fire was close only after it was too late to safely evacuate—Smoke Guard aims to alert users as soon as smoke levels rise, using LEDs and a buzzer to signal safe, moderate, and dangerous smoke levels.

Project Overview
Smoke Guard uses an MQ2 smoke sensor connected to an Arduino Uno R4 WiFi microcontroller to continuously measure smoke density in the air. Based on the detected levels, the system activates color-coded LEDs and a buzzer to indicate air quality and smoke levels:

Green LED: Safe air quality
Blue LED: Moderate smoke levels
Red LED and Buzzer: High smoke levels, indicating a potential hazard
In future updates, Smoke Guard may integrate IoT capabilities, allowing for remote notifications via Alexa or mobile devices, enabling users to monitor air quality from anywhere.

Screenshots:
<img width="554" alt="Screen Shot 2024-11-11 at 8 42 00 pm" src="https://github.com/user-attachments/assets/dee2a319-a87f-49a9-a16c-96b629d91917">

Components Used
Arduino Uno R4 WiFi: Microcontroller for processing sensor data and controlling output components
MQ2 Smoke Sensor: Detects smoke and other gases in the air, outputting an analog signal
LEDs (Green, Blue, Red): Provide visual indicators for different levels of smoke density
Buzzer: Sounds an alarm at high smoke levels to ensure immediate awareness
Breadboard and Jumper Wires: For circuit connections
Code Explanation
The core code reads and processes the analog output from the MQ2 smoke sensor, comparing it against predefined smoke density thresholds to control the LEDs and buzzer:

Threshold Setup
The program uses three threshold values to determine smoke levels:

const int smokeThresholdGreen = 50;    // Green LED (safe air quality, 0 - 50)
const int smokeThresholdBlue = 250;    // Blue LED (moderate smoke, 51 - 250)
const int smokeThresholdRed = 251;     // Red LED and buzzer (high smoke, 251+)
These values specify ranges for safe, moderate, and hazardous smoke levels. When the smoke level falls below 50, the air is considered safe, activating only the green LED. Moderate smoke levels between 51 and 250 activate the blue LED, while levels at 251 or above activate the red LED and the buzzer to warn of a high smoke density.

Setup Function
In the setup() function, the code initializes the pins and sets the LEDs and buzzer as outputs, while the smoke sensor is set as an input:

void setup() {
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600); // Initialize serial monitor for debugging
}
This ensures each component is configured correctly for the main loop to control their state based on sensor readings.

Main Loop
The loop() function handles reading the smoke level from the MQ2 sensor, deciding which LED and buzzer state to activate, and printing the current smoke level to the Serial Monitor for monitoring.

Reading the Smoke Level:

int smokeLevel = analogRead(sensorPin);
Serial.print("Smoke Level: ");
Serial.println(smokeLevel);
The analog value from the sensor is read and displayed in the Serial Monitor, enabling real-time monitoring of the smoke density.

Conditionally Activating LEDs and Buzzer: Based on the smoke level reading, the system determines which LED (or LEDs) and whether the buzzer should be on. The logic follows the thresholds defined above:

Safe Air Quality (smokeLevel < smokeThresholdGreen):
The green LED is turned on, indicating safe air quality, with the buzzer and other LEDs off.

digitalWrite(greenLEDPin, HIGH);
digitalWrite(blueLEDPin, LOW);
digitalWrite(redLEDPin, LOW);
noTone(buzzerPin);
Moderate Smoke Level (smokeThresholdGreen <= smokeLevel < smokeThresholdBlue):
The blue LED turns on, signaling a moderate level of smoke. Other LEDs and the buzzer are turned off.

digitalWrite(greenLEDPin, LOW);
digitalWrite(blueLEDPin, HIGH);
digitalWrite(redLEDPin, LOW);
noTone(buzzerPin);
High Smoke Level (smokeLevel >= smokeThresholdRed):
Both the red LED and the buzzer are activated to indicate dangerous smoke levels.

digitalWrite(greenLEDPin, LOW);
digitalWrite(blueLEDPin, LOW);
digitalWrite(redLEDPin, HIGH);
tone(buzzerPin, 1000);  // Set the buzzer to emit a 1000 Hz tone as an alarm
Delay: After each loop, a 500ms delay prevents excessive readings and stabilizes the system.

delay(500);
Serial Monitoring
Throughout the loop, smoke levels are printed to the Serial Monitor, helping to debug and track how the system responds to real-time changes in air quality.

Libraries Used

1. Arduino Core Library**  
   - Installation**: This library comes pre-installed with the Arduino IDE. No additional installation is required.
   - Documentation**: [Arduino Reference](https://www.arduino.cc/reference/en/)

2. MQ2 Gas Sensor Library**  
   - Installation:
     - Open the Arduino IDE.
     - Go to Sketch > Include Library > Manage Libraries....
     - Search for "MQSensorsLib" or manually add it from [GitHub](https://github.com/miguel5612/MQSensorsLib).
   - Documentation**: Available on the [GitHub repository](https://github.com/miguel5612/MQSensorsLib)

(Optional) WiFi and IoT Libraries: For potential remote notifications in future updates
ESP8266 WiFi Module  
   - Installation:
     - Go to File > Preferences in the Arduino IDE.
     - In Additional Boards Manager URLs, add `http://arduino.esp8266.com/stable/package_esp8266com_index.json`.
     - Go to Tools > Board > Boards Manager..., search for "ESP8266," and install the **ESP8266 by ESP8266 Community package.
   - Documentation: [ESP8266 Arduino Core Documentation](https://arduino-esp8266.readthedocs.io/en/latest/)

Future Enhancements
Alexa & Mobile Notifications: Integrate remote alerts via Alexa or mobile apps, allowing users to monitor smoke levels away from the device.
Enhanced Calibration: Fine-tune the threshold values to better match specific environmental conditions for more accurate readings.

How to Use
Circuit Setup: Connect the Arduino, MQ2 sensor, LEDs, and buzzer as per the provided circuit diagram.
Upload Code: Open the code in Arduino IDE and upload it to the Arduino Uno R4 WiFi.
Monitor Air Quality: Use the Serial Monitor to view real-time smoke level readings.
Respond to Alerts: Observe the LEDs and buzzer as indicators of current air quality.
