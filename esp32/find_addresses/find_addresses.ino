#include <WiFi.h>
#include <WiFiUdp.h>
#include "Wire.h"

// I2C Pins
#define I2C_SDA_PIN 21
#define I2C_SCL_PIN 19
#define I2C_FREQ 100000

// Your WiFi credentials
#define WIFI_SSID "YOUR_WIFI_SSID"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWRD"

// UDP settings
#define HOST_IP "YOUR_HOST_IP"
#define UDP_PORT 12345


// WiFI - UDP
WiFiUDP udp;

bool wifi_log(const char* msg) {
  bool status = true;
  status &= udp.beginPacket(HOST_IP, UDP_PORT);
  udp.print(msg);
  status &= udp.endPacket();
  return status;
}

void setup() {
  // Connect to WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
  wifi_log("Connected to WiFi\n");

  // Setup I2C
  if(Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN))
    wifi_log("Initialized I2C interface\n");
  else
    wifi_log("Could not initialize I2C interface\n");
}

void loop() {
  byte error, address;
  int nDevices = 0;
  char msg[34];
  
  // Send a simple plain text message
  wifi_log("Scanning for I2C devices...\n");
  for (address = 0x01; address < 0x7f; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0) {
      sprintf(msg, "I2C device found at address 0x%02X\n", address);
      wifi_log(msg);
      nDevices++;
    } else if (error != 2) {
      sprintf(msg, "Error %d at address 0x%02X\n", error, address);
      wifi_log(msg);
    }
  }
  if (nDevices == 0) {
    wifi_log("No I2C devices found\n");
  }

  // Delay 5 seconds and repeat scan
  delay(5000);
}

/*
  Connected to WiFi
  Initialized I2C interface
  Scanning for I2C devices...
  Scanning for I2C devices...
  I2C device found at address 0x2C
  I2C device found at address 0x2D
 */