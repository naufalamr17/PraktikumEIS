#define ledPin 7
#define Sensor A0

void setup() {
  // put your setup code here, to run once:
  pinMode(Sensor, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("MQ5 Heating Up!");
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  int gas_value = analogRead(Sensor);
  Serial.print("Sensor Value: ");
  Serial.println(gas_value);
  if (gas_value > 100){
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
