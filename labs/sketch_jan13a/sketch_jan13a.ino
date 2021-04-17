void setup() {
  pinMode(8, INPUT_PULLUP); // switch connected to pin 8
  pinMode(13, OUTPUT);
}
  
void loop() {
  int value=digitalRead(8); // to read the switcheroo
  digitalWrite(13,value); // Show switch on led
  delay(100);
}
  
  
