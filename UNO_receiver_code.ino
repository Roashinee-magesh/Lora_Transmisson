#include <SPI.h>
#include <LoRa.h>

#define SS   10      // UNO NSS pin
#define RST  9
#define DIO0 2

void setup() {
  Serial.begin(9600);
  Serial.println("LoRa Receiver");

  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa init failed!");
    while (1);
  }

  Serial.println("Receiver Ready");
}

void loop() {

  int packetSize = LoRa.parsePacket();

  if (packetSize) {
    Serial.println("Received:");

    String receivedLine = "";

    while (LoRa.available()) {
      receivedLine += (char)LoRa.read();
    }

    Serial.println(receivedLine);
    Serial.println("------------------");
  }
}
