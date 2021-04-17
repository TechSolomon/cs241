// Benjamin Stream & Solomon Himelbloom
// Assignment 1

const int RELAY_PIN = 2;
void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
  delay(1000);
  digitalWrite(RELAY_PIN, HIGH);
}
