void setup() {
  for (int i; i < nhardwire; i++) {
    pinMode(pin_for_hardwire[i], OUTPUT);
  }
}


void loop() {
  for (int i; i < nhardwire; i++) {
    digitalWrite(pin_for_hardwire[i], HIGH);
    delay(1000);
    digitalWrite(pin_for_hardwire[i + 1], LOW);
    delay(1000);
  }

   for (int i; i < nhardwire; i--) {
    digitalWrite(pin_for_hardwire[i], HIGH);
    delay(1000);
    digitalWrite(pin_for_hardwire[i - 1], LOW);
    delay(1000);
  }
}
