#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT11.h>

DHT11 dht11(2); //pin sensor dht

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
  float temperature = dht11.readTemperature();   // Membaca suhu dalam Celsius
  float humidity = dht11.readHumidity();         // Membaca kelembaban
  Serial.println(temperature);            // Menampilkan temperature pada Serial Monitor
  Serial.println(humidity);            // Menampilkan humidity pada Serial Monitor

  if (isnan(temperature) || isnan(humidity))
  {
    Serial.println("Gagal membaca data dari sensor DHT11!");
    return;
  }

  Blynk.virtualWrite(V7, temperature);   // Mengirim suhu ke pin virtual V5 di aplikasi Blynk
  Blynk.virtualWrite(V8, humidity);      // Mengirim kelembaban ke pin virtual V6 di aplikasi Blynk
  delay(2000);  // Menunda pengambilan data selama 2 detik
}
