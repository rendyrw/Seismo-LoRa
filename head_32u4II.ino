#include <SPI.h>
#include <LoRa.h>

#define SS 8
#define RST 4
#define DI0 7
#define BAND 921E6

String data = "";
uint16_t nodeid = 0;

void getData() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    String receivedData = "";
    while (LoRa.available()) {
      receivedData += (char)LoRa.read();
    }
    Serial.println("Data diterima :" + receivedData);
  }
}

/// KE GATEWAY ///

void setup() {
  Serial.begin(9600);
  while(!Serial);

  LoRa.setPins(SS, RST, DI0);
  if(!LoRa.begin(BAND)) {
    Serial.println("gagal memuat lora");
    while(true);
  }
  Serial.println("Memulai LoRa sukses");
}

void loop() {
  getData();
  delay(1000);
}
