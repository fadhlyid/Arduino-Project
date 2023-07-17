#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "NS2aP2GQrIcFl6z3SjK9_Y1clvELAQrm";  // Masukkan token otentikasi Blynk
char ssid[] = "vivo1802";            // Masukkan nama SSID WiFi
char pass[] = "1234567890";      // Masukkan kata sandi WiFi

int redPin = D1;    // Pin D1 (GPIO5) terhubung ke pin merah LED RGB
int greenPin = D2;  // Pin D2 (GPIO4) terhubung ke pin hijau LED RGB
int bluePin = D3;   // Pin D3 (GPIO0) terhubung ke pin biru LED RGB

WidgetLED ledRed(V0);     // Widget LED Blynk untuk kontrol merah
WidgetLED ledGreen(V1);   // Widget LED Blynk untuk kontrol hijau
WidgetLED ledBlue(V2);    // Widget LED Blynk untuk kontrol biru

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V0)
{
  int ledValue = param.asInt();  // Menerima nilai dari tombol di aplikasi Blynk (pin virtual V1)

  if (ledValue == HIGH)
  {
    digitalWrite(redPin, HIGH);  // Menghidupkan LED merah
    ledRed.on();                   // Menghidupkan widget LED 1
  }
  else
  {
    digitalWrite(redPin, LOW);   // Mematikan LED merah
    ledRed.off();                  // Mematikan widget LED 1
  }
}

BLYNK_WRITE(V1)
{
  int ledValue = param.asInt();  // Menerima nilai dari tombol di aplikasi Blynk (pin virtual V2)

  if (ledValue == HIGH)
  {
    digitalWrite(greenPin, HIGH);  // Menghidupkan LED hijau
    ledGreen.on();                     // Menghidupkan widget LED 2
  }
  else
  {
    digitalWrite(greenPin, LOW);   // Mematikan LED hijau
    ledGreen.off();                    // Mematikan widget LED 2
  }
}

BLYNK_WRITE(V2)
{
  int ledValue = param.asInt();  // Menerima nilai dari tombol di aplikasi Blynk (pin virtual V3)

  if (ledValue == HIGH)
  {
    digitalWrite(bluePin, HIGH);  // Menghidupkan LED biru
    ledBlue.on();                    // Menghidupkan widget LED 3
  }
  else
  {
    digitalWrite(bluePin, LOW);   // Mematikan LED biru
    ledBlue.off();                   // Mematikan widget LED 3
  }
}
BLYNK_WRITE(V3)  // Mendeteksi perubahan pada slider RGB merah di aplikasi Blynk
{
  int redValue = param.asInt();
  analogWrite(redPin, redValue);       // Mengatur intensitas kecerahan merah dengan PWM
  ledRed.setValue(redValue / 255);     // Memperbarui nilai LED Blynk merah
}

BLYNK_WRITE(V4)  // Mendeteksi perubahan pada slider RGB hijau di aplikasi Blynk
{
  int greenValue = param.asInt();
  analogWrite(greenPin, greenValue);   // Mengatur intensitas kecerahan hijau dengan PWM
  ledGreen.setValue(greenValue / 255); // Memperbarui nilai LED Blynk hijau
}

BLYNK_WRITE(V5)  // Mendeteksi perubahan pada slider RGB biru di aplikasi Blynk
{
  int blueValue = param.asInt();
  analogWrite(bluePin, blueValue);     // Mengatur intensitas kecerahan biru dengan PWM
  ledBlue.setValue(blueValue / 255);   // Memperbarui nilai LED Blynk biru
}
