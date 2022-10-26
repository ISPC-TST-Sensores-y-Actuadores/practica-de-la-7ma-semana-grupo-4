#include <Arduino.h>
#include <RH_ASK.h>
#include <SPI.h>
//#include <LoRa.h>
RH_ASK driver;
void setup()

{
  driver.init();
  Serial.begin(9600);

  // if (!LoRa.begin(433E6))
  // {
  //   Serial.println("Starting LoRa failed!");
  //   while (1)
  //     ;
  // }
}
void loop()
{
  uint8_t buf[100];
  uint8_t buflen = sizeof(buf);
  if (driver.recv(buf, &buflen)) // Non-blocking
  {
    Serial.print("el mensaje recibido es: ");
    Serial.println((char *)buf);
  }
  // int packetSize = LoRa.parsePacket();
  // if (packetSize)
  // {
  //   Serial.print("Recibiendo mensaje ");
  //   while (LoRa.available())
  //   {
  //     Serial.print((char)LoRa.read());
  //     // str=str+((char)LoRa.read());
  //   }
  //   Serial.print("' with RSSI ");
  //   Serial.println(LoRa.packetRssi());
  // }
}