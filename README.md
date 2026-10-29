# IoT-Based Air Quality Monitoring System with Real-Time Web Dashboard
<img width="1536" height="1024" alt="image" src="https://github.com/user-attachments/assets/925d8a0d-f581-41fa-a7da-6032ba56c6bf" />


Stimulation Access Link :- https://wokwi.com/projects/472976271816115201
Presentation PPT Link :- https://docs.google.com/presentation/d/1CxxoGmHysMZz8GWxRckmiLMYroXpbxYA/edit?usp=drive_link&ouid=100996874504024036206&rtpof=true&sd=true


## Project Overview
The IoT-Based Air Quality Monitoring System is designed to monitor environmental conditions using an ESP32 microcontroller, DHT11 temperature and humidity sensor, and MQ-135 gas sensor. Sensor readings will be displayed on an OLED screen and transmitted over Wi-Fi to a cloud platform.

After completing the hardware implementation and testing, the project will be extended with a web-based monitoring dashboard to visualize real-time sensor readings, track historical data, and provide an easy-to-understand overview of environmental conditions.

## Key Features
- Real-time temperature and humidity monitoring
- Air-quality sensor readings using the MQ-135
- Live data display on an OLED screen
- Wi-Fi connectivity using a mobile hotspot or wireless network
- Cloud data storage and visualization using ThingSpeak
- Planned web dashboard for real-time data visualization
- Planned historical graphs and sensor trends
- Planned visual alerts when readings exceed configured thresholds

## Hardware Components
- ESP32 development board
- DHT11 temperature and humidity sensor
- MQ-135 gas sensor module
- SSD1306 I2C OLED display
- Breadboard and jumper wires
- USB power and Wi-Fi connectivity

## Software and Technologies
- Arduino IDE and embedded C++
- ESP32
- ThingSpeak IoT cloud platform
- HTML, CSS, and JavaScript for the planned web dashboard
- Web APIs for retrieving sensor data

## System Workflow
1. The sensors collect temperature, humidity, and gas-sensor readings.
2. The ESP32 processes the sensor readings.
3. The OLED displays the readings locally.
4. The ESP32 sends data over Wi-Fi to ThingSpeak.
5. The planned website retrieves the available data and displays it through charts, status indicators, and historical trends.

## Future Enhancements
- Responsive dashboard for desktop and mobile devices
- Real-time data refresh and interactive charts
- Historical data analysis
- Configurable threshold alerts
- Improved sensor calibration and more meaningful air-quality estimates

## Project Status
**Phase 1:** Hardware setup, sensor integration, and OLED display.

**Phase 2:** Wi-Fi connectivity and ThingSpeak cloud integration.

**Phase 3:** Web dashboard development for real-time monitoring.

## Important Note
The MQ-135 provides sensor readings that require calibration and interpretation. Raw readings alone do not represent a certified Air Quality Index (AQI).

## Author
Kapil Kumar Gupta
## Note
MQ-135 raw readings are not equivalent to a certified AQI measurement. Accurate gas concentration estimates require appropriate calibration and validation.
