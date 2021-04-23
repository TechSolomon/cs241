// Solomon Himelbloom
// CS 241 Final Project
// Bear Aware Smart Latch

#include <Servo.h>

// Servo
Servo latch;
const int servoPin = 9;
int pos = 0;

// Water Sensor
const int analogInPin = A0;
int sensorValue = 0;

// RGB LED (red, green, & blue pins)
const char ledPins[3] = {2, 3, 4};
int ledTime = 0;

// Default Color Presets
int red[4] = {500, 0, 0};
int green[5] = {0, 500, 0};
int blue[6] = {0, 0, 500};
int low[7] = {0, 500, 0};
int medium[8] = {500, 500, 250};
int high[9] = {500, 0, 0};

void getServoState() {
  // 0 degrees to 180 degrees.
  for (pos = 0; pos <= 180; pos += 1) {
    latch.write(pos);
    delay(15);
  }

  // 180 degrees to 0 degrees.
  for (pos = 180; pos >= 0; pos -= 1) {
    latch.write(pos);
    delay(15);
  }
}

void lock() {
  // 0 degrees to 180 degrees.
  for (pos = 0; pos <= 45; pos += 1) {
    latch.write(pos);
    delay(15);
  }

  int denied[10] = {500, 0, 0};
  showColor(denied);
}

void unlock() {
  // 180 degrees to 0 degrees.
  for (pos = 45; pos >= 0; pos -= 1) {
    latch.write(pos);
    delay(15);
  }

  int granted[6] = {0, 500, 0};
  showColor(granted);
}

void getWaterLevel() {
  sensorValue = analogRead(analogInPin);

  Serial.print("Water Level = " );
  Serial.println(sensorValue);

  delay(1000);
}

// KEY: color[0]==red, color[1]==green, & color[2]==blue.
void showColor(const int *color) {
  int totalDelay = 0;
  for (int colorIndex = 0; colorIndex < 3; colorIndex++) {
    for (int pinIndex = 0; pinIndex < 3; pinIndex++) {
      digitalWrite(ledPins[pinIndex], colorIndex == pinIndex);
    }
    delayMicroseconds(color[colorIndex]);
    totalDelay += color[colorIndex];
  }

  for (char p : ledPins) {
    digitalWrite(p, 0);
  }

  // Takes 3 milliseconds.
  delayMicroseconds(3000 - totalDelay);
}

void getCurrentColor() {
  int color[3] = {ledTime / 10, 0, 500 - ledTime / 10};
  showColor(color);
  ledTime++;
  if (ledTime > 5000) ledTime = 0;
}

void setup() {
  Serial.begin(9600);

  Serial.print("Bear Aware Smart Latch\n");
  Serial.print("CS 241 Final Project by Solomon Himelbloom\n");
  Serial.print("-=-=-=-=-=-=-=-=-=-=-\n");
  Serial.print("Ready for commands.\n");
  Serial.print("*: Clears buffer.\n");

  for (char p : ledPins) pinMode(p, OUTPUT);

  // Attaches the servo (pin 9) to the latch object.
  latch.attach(9);
}

String buffer;

void clearBuffer() {
  buffer = "";
}

void instructions() {
  while (Serial.available()) {
    char c = Serial.read();
    buffer += c;

    switch (c) {
      // Manual Buffer Clear
      case '*':
        Serial.print("Clearing Buffer...\n");
        Serial.print("Current Buffer:" + buffer + "\n");
        clearBuffer();
        Serial.print("Buffer Cleared!\n");

      case 'p':
        if (buffer == "help") {
          // Print a brief summary of supported commands.
          Serial.print("\nHelp Menu:\n");
          Serial.print("*: Clears buffer.\n");
          Serial.print("ok: Checks the Arduino status.\n");
          Serial.print("water: Checks the water sensor.\n");
          Serial.print("i: Locks the Smart Latch.\n");
          Serial.print("o: Unlocks the Smart Latch.\n");
          clearBuffer();
        }

      case 'k':
        //  Useful for checking if the Arduino is still alive.
        if (buffer == "ok") {
          Serial.print("OK\n");
          clearBuffer();
        }

      case 'r':
        // Check the water level.
        if (buffer = "water") {

          for (int checkDepth = 0; checkDepth < 20; checkDepth++) {
            getWaterLevel();

            if (sensorValue = 0) {
              Serial.println("[WATER EMPTY]");
            }

            else if (sensorValue > 0 && sensorValue <= 300) {
              Serial.println("[LOW LEVEL]");
            }

            else if (sensorValue > 300 && sensorValue <= 500) {
              Serial.println("[MEDIUM LEVEL]");
            }

            else if (sensorValue > 500) {
              Serial.println("[HIGH LEVEL]");
            }
          }

          // TODO: Change LED color depending on the water depth.
          // getCurrentColor();

          clearBuffer();
        }

      case 'i':
        // Locks the Smart Latch.
        if (buffer == "i") {
          lock();
          Serial.print("Roll Cart: [LOCKED]\n");
          clearBuffer();
        }

      default:

      case 'o':
        // Unlocks the Smart Latch.
        if (buffer == "o") {
          unlock();
          Serial.print("Roll Cart: [UNLOCKED]\n");
          clearBuffer();
        }

    }
    delay(1000);
  }
}

// TODO: Fix flickering RGB LED with water inputs.
void loop() {
  instructions();
  //  getServoState();
  //  getWaterLevel();
  //  getCurrentColor();
}