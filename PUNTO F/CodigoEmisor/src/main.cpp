#include <Arduino.h>
#include <RH_ASK.h>
#include <SPI.h>
#include <DHT.h>          // Libreria de sensor DHT11
#include <DHT_U.h>        // Librería de control DTH11
#define DHTPIN 8          // Pin de conexión del sensor DHT11
#define DHTTYPE DHT11     // difino cual es el sensor que ese usa, en este caso DHT 11
DHT dht(DHTPIN, DHTTYPE); // Inicializo el sensor DHT11
//#include <LoRa.h>

RH_ASK driver;
void setup()
{
  driver.init();
  dht.begin(); // Inicializo el sensor DHT11
               // if (!LoRa.begin(433E6))
               // {
               //   Serial.println("Starting LoRa failed!");
               //   while (1)
               //     ;
               // }
}
void loop()
{
  float h = dht.readHumidity();  // Tomo en la variable el dato de la humedad
  int t = dht.readTemperature(); // Tomo en la variable el dato de la humedad

  if (isnan(h) || isnan(t)) // Chequeo que las lecturas sean correctas
  {
    Serial.println("Error al obtener lecturas del sensor!"); // Pruebas por pantalla serie
    return;
  }
  // std::string cadena = "hola mundo";
  // char buffer[100];
  // strcpy(buffer, cadena.c_str());
  // std::cout << buffer;
  char msg[100];
  String mje = "Temperatura: " + String(t) + " *C" + " Humedad: " + String(h) + " %"; // Creo el mensaje a enviar
  strcpy(msg, mje.c_str());                                                           // Convierto el mensaje a char
  Serial.print("Enviando mensaje ");
  Serial.println(msg);

  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  delay(300);
  // LoRa.beginPacket();
  // LoRa.print(msg);
  // LoRa.endPacket();
}