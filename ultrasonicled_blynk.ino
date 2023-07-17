#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define TRIGGER_PIN D1    // Pin D1 (GPIO5) terhubung ke pin Trigger sensor ultrasonik
#define ECHO_PIN D2       // Pin D2 (GPIO4) terhubung ke pin Echo sensor ultrasonik
#define LED_PIN D3        // Pin D3 (GPIO0) terhubung ke lampu LED

char auth[] = "NS2aP2GQrIcFl6z3SjK9_Y1clvELAQrm";  // Masukkan token otentikasi Blynk
char ssid[] = "vivo1802";            // Masukkan nama SSID WiFi
char pass[] = "1234567890";      // Masukkan kata sandi WiFi

BlynkTimer timer;

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  Blynk.virtualWrite(V1, LOW);  // Inisialisasi status tombol switch pada aplikasi Blynk sebagai OFF

  timer.setInterval(1000L, checkDistance);  // Mengecek jarak setiap 1 detik
}

void loop()
{
  Blynk.run();
  timer.run();
}

void checkDistance()
{
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2;  // Menghitung jarak dalam centimeter

  Blynk.virtualWrite(V6, distance);  // Mengirim jarak ke pin virtual V6 di aplikasi Blynk
  Serial.println(distance);            // Menampilkan jarak pada Serial Monitor


  if (distance < 5 ) {
    digitalWrite(LED_PIN, HIGH);  // Menyalakan lampu LED
  } else {
    digitalWrite(LED_PIN, LOW);   // Mematikan lampu LED
  }
}

