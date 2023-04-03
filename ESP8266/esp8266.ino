#include <DHT.h>

#define DHTPIN D4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.println("Gagal membaca data dari sensor DHT");
    return;
  } else {
    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.print(F("  Temperature: "));
    Serial.print(t);
    Serial.print(F("°C "));
    Serial.print("\n");
  }
  delay(10000);
}
