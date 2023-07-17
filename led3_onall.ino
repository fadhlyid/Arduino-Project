#include <ESP8266WiFi.h>

#define LED_PIN_1 D1  // Pin D1 (GPIO5) terhubung ke LED 1
#define LED_PIN_2 D2  // Pin D2 (GPIO4) terhubung ke LED 2
#define LED_PIN_3 D3  // Pin D3 (GPIO0) terhubung ke LED 3

void setup()
{
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
}

void loop()
{
  digitalWrite(LED_PIN_1, HIGH);  // Menghidupkan LED 1
  digitalWrite(LED_PIN_2, HIGH);  // Menghidupkan LED 2
  digitalWrite(LED_PIN_3, HIGH);  // Menghidupkan LED 3
}
