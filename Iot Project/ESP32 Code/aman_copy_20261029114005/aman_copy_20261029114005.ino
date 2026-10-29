
#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <DHT.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// -------- SENSOR PINS --------
#define DHT_PIN 4
#define DHT_TYPE DHT11
#define MQ135_PIN 34

// -------- OLED SETTINGS --------
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

DHT dht(DHT_PIN, DHT_TYPE);

Adafruit_SSD1306 display(
  SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1
);

// -------- YOUR WIFI DETAILS --------
const char* ssid = "Aman";
const char* password = "";

// -------- THINGSPEAK DETAILS --------
const char* writeAPIKey = "U6E6DCMHQX62A9PE";

const char* server = "http://api.thingspeak.com/update";

unsigned long lastRead = 0;
unsigned long lastUpload = 0;

float temperature = 0;
float humidity = 0;
int airValue = 0;
int statusCode = 0;

String airStatus = "STARTING";

void setup() {
  Serial.begin(115200);

  analogReadResolution(12);

  dht.begin();
  Wire.begin(21, 22);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED initialization failed!");
    while (true) {
      delay(100);
    }
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Air Quality Monitor");
  display.println("Starting...");
  display.display();

  Serial.println("Connecting to Wi-Fi...");
  WiFi.begin(ssid);

  unsigned long startTime = millis();

  while (WiFi.status() != WL_CONNECTED &&
        millis() - startTime < 20000) {
    delay(500);
    Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWi-Fi connected!");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nWi-Fi connection failed!");
  }

    Serial.println("\nWi-Fi connected!");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }

void loop() {
  unsigned long now = millis();

  // Read sensors every 2 seconds
  if (now - lastRead >= 2000) {
    lastRead = now;

    float t = dht.readTemperature();
    float h = dht.readHumidity();

    if (!isnan(t) && !isnan(h)) {
      temperature = t;
      humidity = h;
    } else {
      Serial.println("DHT11 reading failed!");
    }

    airValue = analogRead(MQ135_PIN);

    // Demonstration thresholds only.
    // Calibrate using your actual sensor readings.
    if (airValue < 1200) {
      airStatus = "GOOD";
      statusCode = 0;
    } else if (airValue < 2500) {
      airStatus = "MODERATE";
      statusCode = 1;
    } else {
      airStatus = "POOR";
      statusCode = 2;
    }

    Serial.printf("Temperature: %.1f C\n", temperature);
    Serial.printf("Humidity: %.1f %%\n", humidity);
    Serial.printf("Air sensor raw value: %d\n", airValue);
    Serial.println("Status: " + airStatus);

    // Update OLED
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("AIR QUALITY MONITOR");
    display.println("--------------------");

    display.print("Temp: ");
    display.print(temperature, 1);
    display.println(" C");

    display.print("Humidity: ");
    display.print(humidity, 1);
    display.println(" %");

    display.print("Air Value: ");
    display.println(airValue);

    display.print("Status: ");
    display.println(airStatus);

    display.display();
  }

  // Upload to ThingSpeak every 20 seconds
  if (now - lastUpload >= 20000) {
    lastUpload = now;

    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http;

      String url = String(server)
        + "?api_key=" + writeAPIKey
        + "&field1=" + String(temperature, 1)
        + "&field2=" + String(humidity, 1)
        + "&field3=" + String(airValue)
        + "&field4=" + String(statusCode);

      http.begin(url);
      int httpCode = http.GET();

      if (httpCode > 0) {
        String response = http.getString();
        Serial.print("ThingSpeak response: ");
        Serial.println(response);
      } else {
        Serial.print("HTTP error: ");
        Serial.println(http.errorToString(httpCode));
      }

      http.end();
    } else {
      Serial.println("Wi-Fi disconnected; upload skipped.");
    }
  }
}
