/*
   Benjamin Stream & Solomon Himelbloom

   Credit to:
  Simple test driver program for an ultrasonic distance sensor
  Dr. Orion Lawlor, lawlor@alaska.edu, 2021-01-31 (Public Domain)
*/

/* Pins used:
   gnd - arduino ground
   echo - pin 13  (is this a good idea?  it shares the LED)
   trigger - pin 11
   vcc - 5v
   servo - pin 2
*/
#include <Servo.h>

Servo serv;
const int pin_echo = 13;
const int pin_trigger = 11;
const int pin_servo = 2;
const int max_distance = 10000; // big invalid distance value

/* Return distance in millimeters, as measured by ultrasonic sensor.
   If nothing is returned from the sensor, return max_distance.
   This call takes between 8ms and 25ms.
*/

unsigned int read_distance() {
  /* Activate trigger pin for 10us */
  digitalWrite(pin_trigger, HIGH);
  delayMicroseconds(10); /* fire! */
  digitalWrite(pin_trigger, LOW);

  /* Read back echo duration from pulse length on echo pin.
     Echo lengths longer than this limit are tough to achieve in practice.
  */
  long time_us = pulseIn(pin_echo, HIGH, 25000);

  if (time_us == 0) { /* we timed out.  Report an invalid distance */
    return max_distance;
  }


  /* The sensor can't be triggered too often, or it stops returning pulses */

  int time_ms = time_us / 1024;
  const int min_ms = 8; // minimum number of milliseconds per pulse

  if (time_ms < min_ms) delay(min_ms - time_ms);
  /* Convert time to distance, via speed of sound in mm/us, and factor of 2 round trip */
  int dist_mm = (int)(time_us * (0.343 / 2));
  return dist_mm;

}

unsigned long sendServo(int degree) {
  serv.write(degree);
}

void setup()

{
  /* Set pin modes for the sensor pins */
  serv.attach(pin_servo); // servo's white wire is on pin D2
  pinMode(pin_echo, INPUT);
  pinMode(pin_trigger, OUTPUT); digitalWrite(pin_trigger, LOW);
  Serial.begin(9600); // for debug info
  Serial.println("Ultrasonic echo detector");
}

int position = 0; // Initial servo position
int count = 0;

void loop() {
    sendServo(position);
    delay(1000);

  while (position <= 360) {

    sendServo(position);
    position+= 5;

    int distance = read_distance();



    if (count <= 50) {

      Serial.print(millis()); // Time (ms)
      Serial.print("\t");
      Serial.print(distance); // Distance (mm)
      Serial.print("\t");
      Serial.println(position); // Servo command (%)

    }

    delay(10); // max 100Hz

    count++;

  }
  sendServo(position);
    delay(1000);
}
