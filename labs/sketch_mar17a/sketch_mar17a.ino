void setup() {
  Serial.begin(9600);
  Serial.println("Command demo!");
}

String buffer;

void loop() {
  while (Serial.available() > 0) {
    int c = Serial.read();
    if (c < 0) break;
    if (c == '\n') { // newline, check for a valid command
      //      handleCommand(buffer);
      buffer = "";
    }

    // normal non-control char, just add it to the string
    else if (c != '\r') {
      buffer += (char)c;
    }

  }

  // … do normal work here: blink LEDs, etc

}
