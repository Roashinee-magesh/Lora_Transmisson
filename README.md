LoRa Communication (ESP32 → Arduino UNO)

This project demonstrates LoRa communication between:
ESP32 (Transmitter)
Arduino UNO (Receiver)
SX1278 LoRa Module (433 MHz)

Hardware Used:
ESP32 Dev Module
Arduino UNO
SX1278 LoRa Module (433 MHz)
433 MHz Antenna

ESP32 Transmitter Wiring:
LoRa to ESP32
NSS	5
MOSI	23
MISO	19
SCK	18
RST	14
DIO0	26
VCC	3.3V
GND	GND

Arduino UNO Receiver Wiring:
LoRa to UNO
NSS	10
MOSI	11
MISO	12
SCK	13
RST	9
DIO0	2
VCC	3.3V  
GND	GND


Frequency:
Both transmitter and receiver use:
433E6

How It Works:
ESP32 sends lines of text one by one.
UNO receives and prints each line.
RSSI (signal strength) is displayed.