void setup() {
  Serial.begin(9600);
}

void loop() {
  int t = analogRead(A0); // raw 0-1023 analog-to-digital reading
  float V = (t*5.0/10.230); // scale to float Volts
  Serial.print("Temperature: ");
  Serial.print(V); // print voltage / 250 (in volts)
  Serial.println(" °C");
  delay(1000); // wait for 1 second
}
