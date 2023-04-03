#include <ESP8266WiFi.h>
#include <DHT.h>

#define DHTPIN D4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "Wifi.id";
const char* password = "qqqqqqqq";

const char* serverName = "http://localhost/esp/insertdata.php";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.println("Gagal membaca data dari sensor DHT");
    return;
  } 

  String postData = "temperature=" + String(t) + "&humiditiy=" + String(h);
  Serial.println(postData);

  WiFiClient client;
  if (!client.connect(serverName,80)) {
    Serial.println("Gagal terhubung ke server");
    return;
  }

  String request = "GET " + String(serverName) + "/?" + postData + " HTTP/1.1\r\n" + "Host: " + String(serverName) + "\r\n" + "Connection: close \r\n\r\n";

  client.print(request);
  Serial.println("Sukses");
  
  delay(10000);
}
