#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_TEMPLATE_ID "TMPL6j7CdecnD"
#define BLYNK_TEMPLATE_NAME "Final"
#define BLYNK_AUTH_TOKEN "4BJsxvA7Xc8M8-Z-e1-AXgb7DJPql81m"

#define LED_RED D1    // Pin D1 (GPIO5) terhubung ke pin merah LED RGB
#define LED_GREEN D2  // Pin D2 (GPIO4) terhubung ke pin hijau LED RGB
#define LED_BLUE D3   // Pin D3 (GPIO0) terhubung ke pin biru LED RGB
#define TRIGGER_PIN D4    // Pin D4 terhubung ke pin Trigger sensor ultrasonik
#define ECHO_PIN D5       // Pin D5 terhubung ke pin Echo sensor ultrasonik
#define LDR_PIN A0         // Pin analog A0 terhubung ke sensor LDR


char auth[] = "4BJsxvA7Xc8M8-Z-e1-AXgb7DJPql81m";  // Masukkan token otentikasi Blynk
char ssid[] = "vivo1802";            // Masukkan nama SSID WiFi
char pass[] = "1234567890";      // Masukkan kata sandi WiFi

WidgetLED Red_Led(V1);     // Widget LED Blynk untuk kontrol merah
BlynkTimer timer;

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);

  timer.setInterval(1000L, measureDistance);  // Mengukur jarak setiap 1 detik
}

void loop()
{
  Blynk.run(); 

  int lightIntensity = analogRead(LDR_PIN);   // Membaca nilai intensitas cahaya
  Blynk.virtualWrite(V2, lightIntensity);     // Mengirim intensitas cahaya ke pin virtual V5 di aplikasi Blynk
  Serial.println("Intensitas Cahaya (Lux): ") ;
  Serial.println(lightIntensity);            // Menampilkan intensitas cahaya pada Serial Monitor
  if (lightIntensity < 100)
  {
    digitalWrite(LED_GREEN, HIGH);    // Menyalakan lampu hijau
  }
  else
  {
    digitalWrite(LED_GREEN, LOW);     // Mematikan lampu hijau
  }
  delay(1000);  // Menunda pengambilan data selama 1 detik
  timer.run();
}

  BLYNK_WRITE(V1)
{
  int ledValue = param.asInt();  // Menerima nilai dari tombol di aplikasi Blynk (pin virtual V1)

  if (ledValue == HIGH)
  {
    digitalWrite(LED_RED, HIGH);  // Menghidupkan LED merah
 
  }
  else
  {
    digitalWrite(LED_RED, LOW);   // Mematikan LED merah
  
  }
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
  Serial.println("Jarak (cm): ") ;
  Serial.println(distance);            // Menampilkan jarak pada Serial Monitor
  Blynk.virtualWrite(V3, distance);  // Mengirim jarak ke pin virtual V6 di aplikasi Blynk

  if (distance < 5)
  {
    digitalWrite(LED_BLUE, HIGH);    // Menyalakan lampu hijau
  }
  else
  {
    digitalWrite(LED_BLUE, LOW);     // Mematikan lampu hijau
  }
}