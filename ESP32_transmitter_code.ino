#include <SPI.h>
#include <LoRa.h>

#define SS   5
#define RST  14
#define DIO0 26

void setup() {
  Serial.begin(115200);
  Serial.println("ESP32 LoRa Transmitter");

  SPI.begin(18, 19, 23, 5);   
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa init failed!");
    while (1);
  }

  Serial.println("Transmitter Ready");
}

void loop() {

  String lines[] = {
    "Never gonna give you up",
    "Never gonna let you down",
    "Never gonna run around and desert you",
    "Never gonna make you cry",
    "Never gonna say goodbye",
    "Never gonna tell a lie and hurt you"
  };

  for (int i = 0; i < 6; i++) {

    Serial.println("Transmitting:");
    Serial.println(lines[i]);

    LoRa.beginPacket();
    LoRa.print(lines[i]);
    LoRa.endPacket();

    delay(2000);   // 2 second delay between lines
  }

  Serial.println("------------------------");
  delay(10000);   // Wait before repeating
}
