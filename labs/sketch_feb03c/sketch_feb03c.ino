#include <Servo.h>

Servo serv;

void setup() {
  serv.attach(8); // servo's white wire is on pin D8
}

void loop() {
  serv.write(90);  // set servo to mid-point (90 degrees)
  delay(2000); // wait this many milliseconds
  serv.write(30);  // set servo to left (30 degrees)
  
  delay(2000); // wait

} 
