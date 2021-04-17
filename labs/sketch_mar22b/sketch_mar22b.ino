// Benjamin Stream & Solomon Himelbloom
// Assignment 1

void setup() {
  Serial.begin(9600);
  Serial.print("Ready for commands (v1.0)\n");
}

String buffer;


void clearBuffer() {

  buffer = "";

}

// Autoclears Buffer
void analogAnalysis(int pin) {
  int realPin = pin + 13;
  int v = analogRead(realPin); // raw 0-1023 analog-to-digital reading
  float V = 5.0 * v / 1023.0; // scale to float volts
  Serial.print("Raw Reading: ");
  Serial.print(v);
  Serial.print("\n");
  Serial.print("Voltage Reading: ");
  Serial.print(V);
  Serial.print("\n");
  clearBuffer();
}


void loop() {

  while (Serial.available())
  {
    char c = Serial.read();
    buffer += c;
    switch (c)
    {
      // Manual Buffer Clear (if it gets cluttered)
      case '*':
        Serial.print("Clearing Buffer...\n");
        Serial.print("Current Buffer:" + buffer + "\n");
        clearBuffer();
        Serial.print("Buffer Cleared!\n");

      default:
      // testing purposes can be disabed any time
      // Serial.print(buffer + "\n");

      case 'n':
        if (buffer == "\n") {
          Serial.print("NEWLINE\n");
          clearBuffer();
        }

      case 'r':
        if (buffer == "\r") {
          Serial.print("NEWLINEU\n");
          clearBuffer();
        }

      case 'p':
        if (buffer == "help") {
          // "help" should print a brief summary
          // of the currently supported commands.
          Serial.print("Help Menu (Lab 08.1):\n");
          Serial.print("ok: Checks if aurdino is alive\n");
          Serial.print("\\n or \\r: Adds a line of whitespace\n");
          Serial.print("A#: Checks analog ports raw data and voltage 0-5\n");
          clearBuffer();
        }

      case 'k':
        if (buffer == "ok") {
          // “ok" should print "OK"
          // Useful for checking if the Arduino is still alive.
          Serial.print("OK\n");
          clearBuffer();
        }

      case '0':
        if (buffer == "A0") {
          Serial.print("Analysis of A0\n");
          analogAnalysis(c);
        }

      case '1':
        if (buffer == "A1") {
          Serial.print("Analysis of A1\n");
          analogAnalysis(c);
        }

      case '2':
        if (buffer == "A2") {
          Serial.print("Analysis of A2\n");
          analogAnalysis(c);
        }

      case '3':
        if (buffer == "A3") {
          Serial.print("Analysis of A3\n");
          analogAnalysis(c);
        }

      case '4':
        if (buffer == "A4") {
          Serial.print("Analysis of A4\n");
          analogAnalysis(c);
        }

      case '5':
        if (buffer == "A5") {
          Serial.print("Analysis of A5\n");
          analogAnalysis(c);
        }
    }
  }
  delay(1000);
}
