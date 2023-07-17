#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define LDR_PIN A0         // Pin analog A0 terhubung ke sensor LDR

char auth[] = "NS2aP2GQrIcFl6z3SjK9_Y1clvELAQrm";  // Masukkan token otentikasi Blynk
char ssid[] = "vivo1802";            // Masukkan nama SSID WiFi
char pass[] = "1234567890";      // Masukkan kata sandi WiFi

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
  int lightIntensity = analogRead(LDR_PIN);   // Membaca nilai intensitas cahaya

  Blynk.virtualWrite(V9, lightIntensity);     // Mengirim intensitas cahaya ke pin virtual V5 di aplikasi Blynk
  Serial.println(lightIntensity);            // Menampilkan intensitas cahaya pada Serial Monitor

  delay(1000);  // Menunda pengambilan data selama 1 detik
}
