#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "NS2aP2GQrIcFl6z3SjK9_Y1clvELAQrm";  // Masukkan token otentikasi Blynk
char ssid[] = "vivo1802";            // Masukkan nama SSID WiFi
char pass[] = "1234567890";      // Masukkan kata sandi WiFi

int redPin = D4;     // Pin LED merah terhubung ke pin D4 (GPIO2)
int greenPin = D5;   // Pin LED hijau terhubung ke pin D5 (GPIO14)
int bluePin = D6;    // Pin LED biru terhubung ke pin D6 (GPIO12)

WidgetLED led1(V1);  // Widget LED 1 terhubung ke pin virtual V1 di aplikasi Blynk
WidgetLED led2(V2);  // Widget LED 2 terhubung ke pin virtual V2 di aplikasi Blynk
WidgetLED led3(V3);  // Widget LED 3 terhubung ke pin virtual V3 di aplikasi Blynk

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

BLYNK_WRITE(V1)
{
  int ledValue = param.asInt();  // Menerima nilai dari tombol di aplikasi Blynk (pin virtual V1)

  if (ledValue == HIGH)
  {
    digitalWrite(redPin, HIGH);  // Menghidupkan LED merah
    led1.on();                   // Menghidupkan widget LED 1
  }
  else
  {
    digitalWrite(redPin, LOW);   // Mematikan LED merah
    led1.off();                  // Mematikan widget LED 1
  }
}

BLYNK_WRITE(V2)
{
  int ledValue = param.asInt();  // Menerima nilai dari tombol di aplikasi Blynk (pin virtual V2)

  if (ledValue == HIGH)
  {
    digitalWrite(greenPin, HIGH);  // Menghidupkan LED hijau
    led2.on();                     // Menghidupkan widget LED 2
  }
  else
  {
    digitalWrite(greenPin, LOW);   // Mematikan LED hijau
    led2.off();                    // Mematikan widget LED 2
  }
}

BLYNK_WRITE(V3)
{
  int ledValue = param.asInt();  // Menerima nilai dari tombol di aplikasi Blynk (pin virtual V3)

  if (ledValue == HIGH)
  {
    digitalWrite(bluePin, HIGH);  // Menghidupkan LED biru
    led3.on();                    // Menghidupkan widget LED 3
  }
  else
  {
    digitalWrite(bluePin, LOW);   // Mematikan LED biru
    led3.off();                   // Mematikan widget LED 3
  }
}

void loop()
{
  Blynk.run();
}
