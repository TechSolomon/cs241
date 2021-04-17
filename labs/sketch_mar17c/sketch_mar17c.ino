// Benjamin Stream & Solomon Himelbloom
// Assignment 0

void setup() {
  Serial.begin(9600);
  Serial.print("Ready for commands (v0.1: help/whitespace)\n");
}

void loop() {
  while (Serial.available() != 0) {
    int c = Serial.read(); // check RX line
    // Print the received command.
    Serial.print("Command: {");
    Serial.print((char)c);
    Serial.print("} = 0x");
    Serial.print((int)c, HEX);
    Serial.print("\n");

    // "help" should print a brief summary
    // of the currently supported commands.
    if (c == 'p') {
      Serial.print("\n>> Help Menu (Lab 08.0):\n");
      Serial.print("ok: Checks if aurdino is alive\n");
      Serial.print("\\n or \\r: Adds a line of whitespace\n");
    }

    // "ok" should print "OK"
    // Useful for checking if the Arduino is still alive.
    if (c == 'k') {
      Serial.print("OK\n");
    }

    // Checks if \ (92 in ASCII) is inputed.
    if (c == 92) {
      if (c == 'n' || 'r') {
        Serial.print("\n");
      }
    }
  }

  delay(1000);
}
