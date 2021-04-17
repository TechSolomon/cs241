// Benjamin Stream & Solomon Himelbloom
// Assignment 2

void setup() {
  Serial.begin(9600);
  Serial.print("Ready for commands (v2.0: help/whitespace)\n");
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
      Serial.print("i: Turn the pin 13 debug LED on.\n");
      Serial.print("o: Turn the pin 13 debug LED off.\n");
      Serial.print("x: Print 'x' to the serial port 10000 times.\n");
      Serial.print("d: Change the serial baud rate to 19200.\n");
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

    // Turns the LED on.
    if (c == 'i') {
      pinMode(13, OUTPUT);
      digitalWrite(13, 1);
      Serial.print("LED: [ON]\n");
    }

    // Turns the LED off.
    if (c == 'o') {
      pinMode(13, OUTPUT);
      digitalWrite(13, 0);
      Serial.print("LED: [OFF]\n");
    }

    // Print "x" to the serial port.
    if (c == 'x') {
      int i;
      for (int i = 0; i < 9999; i++) {
        Serial.print("x");
      }
    }

    // Change the serial baud rate to 19200.
    if (c == 'd') {
      Serial.flush();
      Serial.begin(19200);
      Serial.flush();
      Serial.begin(9600);
      Serial.print("Are you reading this?\n");
    }

    // Test command names with Unicode chars.
    if (c == 'g') {
      Serial.print("grüning\n");
      Serial.print("Print the chars in hex.\n");
    }
  }

  delay(1000);
}
