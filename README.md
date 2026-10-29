# IoT Air Quality Monitoring System

Stimulation Access Link :- https://wokwi.com/projects/472976271816115201

## Overview
An IoT-based air quality monitoring system built using ESP32. The project reads temperature and humidity using a DHT11 sensor and monitors an analog air-quality sensor (MQ-135). Readings are displayed on an OLED screen and can be uploaded to ThingSpeak using Wi-Fi.

## Components Used
- ESP32 development board
- DHT11 temperature and humidity sensor
- MQ-135 gas sensor module
- I2C OLED display (SSD1306)
- Breadboard and jumper wires
- USB cable and mobile hotspot/Wi-Fi connection

## Features
- Real-time temperature monitoring
- Humidity monitoring
- Analog MQ-135 sensor readings
- Live readings on the OLED display
- Cloud data logging using ThingSpeak
- Wi-Fi connectivity

## Software and Technologies
- Arduino IDE
- Embedded C++ / Arduino framework
- ESP32
- ThingSpeak IoT platform

## Circuit Connections
Add your final wiring diagram and photos in this section.

## How to Run
1. Install Arduino IDE.
2. Install the ESP32 board package.
3. Install the required DHT and Adafruit OLED libraries.
4. Connect the sensors and OLED according to the circuit diagram.
5. Enter your own Wi-Fi credentials and ThingSpeak Write API Key locally.
6. Select your ESP32 board and port.
7. Upload the code and open Serial Monitor at 115200 baud.

## Results
Add photos of the working hardware, OLED output, Serial Monitor, and ThingSpeak graphs after testing.

## Future Improvements
- Calibrate the MQ-135 sensor for more meaningful measurements.
- Add alerts for high sensor readings.
- Build a web dashboard for monitoring historical data.

## Author
Kapil Kumar Gupta

## Note
MQ-135 raw readings are not equivalent to a certified AQI measurement. Accurate gas concentration estimates require appropriate calibration and validation.
