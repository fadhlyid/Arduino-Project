#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define TRIGGER_PIN D1    // Pin D1 (GPIO5) terhubung ke pin Trigger sensor ultrasonik
#define ECHO_PIN D2       // Pin D2 (GPIO4) terhubung ke pin Echo sensor ultrasonik

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

  timer.setInterval(1000L, measureDistance);  // Mengukur jarak setiap 1 detik
}

void loop()
{
  Blynk.run();
  timer.run();
}

void measureDistance()
{
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2;  // Menghitung jarak dalam centimeter
  Serial.println(distance);            // Menampilkan jarak pada Serial Monitor

  Blynk.virtualWrite(V6, distance);  // Mengirim jarak ke pin virtual V6 di aplikasi Blynk
}
