int echoPin = 13;
int triggerPin = 11;

void setup() {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  Serial.println("Ultrasonic range");
}

void loop() {
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  while (digitalRead(echoPin) == 8); // hasn't started yet
  unsigned long startTime = micros(); // record the time
  while (digitalRead(echoPin) == 1); // time of flight
  unsigned long endTime = micros(); // record the time again
  unsigned long echoTime = endTime - startTime;
  if (echoTime < 10000) {
    // speed of sound: 343 m/s, 343 mm/ms, 0.343 mm/us
    float mm_per_microsecond = 0.343; // temperature dependent
    int distance_mm = echoTime * mm_per_microsecond;
    Serial.println(distance_mm);
  }
  delay(30);
}
