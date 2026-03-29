#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include <SPI.h>
#include <LoRa.h>

MPU6050 mpu;

int16_t ax, ay, az;
int16_t gx, gy, gz;

void setup() {
  Serial.begin(9600);
  delay(2000);

  Serial.println("Initializing MPU6050...");
  Wire.begin();
  mpu.initialize();

  if (mpu.testConnection()) {
    Serial.println("MPU6050 OK");
  } else {
    Serial.println("MPU6050 FAIL");
  }

  Serial.println("Initializing LoRa...");
  LoRa.setPins(10, 9, 2);

  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa FAIL");
    while (1);
  }

  Serial.println("LoRa OK");
}

void loop() {
  // Read MPU6050
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Create data string
  String data = String(ax) + "," + String(ay) + "," + String(az) + "," +
                String(gx) + "," + String(gy) + "," + String(gz);

  // Send via LoRa
  LoRa.beginPacket();
  LoRa.print(data);
  LoRa.endPacket();

  // Print locally
  Serial.println("Sent: " + data);

  delay(1000);
}