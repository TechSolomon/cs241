void setup() {
  pinMode(9,INPUT_PULLUP); // switch connected to pin 8/ground
  pinMode(7,OUTPUT); // onboard LED reports status
}

void loop() {
  int button=digitalRead(9);
  if (button==0) { // <- ground!
    Serial.print("PRESSED!\n");
    digitalWrite(7,HIGH);
    delay(10000);
  }

}
