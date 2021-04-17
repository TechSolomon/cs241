// Arduino as a voltmeter (reading in Serial Monitor in Volts)

void setup() {
  Serial.begin(9600);
}

void loop() {
  int v=analogRead(A0); // raw 0-1023 analog-to-digital reading
  float V=5.0*v/1023.0; // scale to float volts
  Serial.println(V); // print voltage (in volts)
  delay(100); // Wait for 100 milliseconds
}
