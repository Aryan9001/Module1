const int temperaturePin = 2;
const int ledPin = 12;         

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}
void loop() {
  int sensorValue = analogRead(temperaturePin);
  float temperatureC = (sensorValue * 0.0048828125 - 0.5) * 100;

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  if (temperatureC > 20.0) {
    digitalWrite(ledPin, HIGH); 
    Serial.println("Temperature exceeds threshold. LED ON");
  } else {
    digitalWrite(ledPin, LOW); 
    Serial.println("Temperature within limits. LED OFF");
    delay(1000);
  }

  delay(1000); 
}