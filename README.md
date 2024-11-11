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
Arduino Uno R4 WiFi: Acts as the primary microcontroller, processing data from the smoke sensor and controlling the outputs (LEDs and buzzer).
MQ2 Smoke Sensor: Detects smoke and various gases in the air, providing an analog signal to represent the smoke density.
LEDs (Green, Blue, Red): Visual indicators representing different smoke levels:
Passive Buzzer: Sounds an alarm at high smoke levels, providing an audible alert for immediate awareness.
220-ohm Resistors: Used with LEDs to limit current, protecting them from excess voltage and preventing burnout.
Breadboard and Jumper Wires: Essential for connecting components without soldering, ensuring easy adjustments.
Power Supply: Provided via a USB-C cable to power the Arduino Uno R4, allowing for portability and convenient connection to a computer or power bank.

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
