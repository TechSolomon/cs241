// Benjamin Stream & Solomon Himelbloom
// Assignment 2

void setup() {
  Serial.begin(9600);
  Serial.print("Ready for commands (v2.0)\n");
  Serial.print("*: Clears buffer.\n");
}

String buffer;
String hexBuffer;

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

      case 'y':
        if (buffer == "new array") {
          // new array size[3] then read array[100]
          Serial.print("Array Magic!\n");
          int magicalArray[3];
          Serial.print(magicalArray[100]);
          Serial.print(": Wow isnt that magical?\n");
          clearBuffer();
        }

      case 'l':
        if (buffer == "null") {
          // Read the pointer "int *ptr=NULL;"
          Serial.print("Reading the null pointer.\n");
          int *ptr = NULL;

          Serial.println(*ptr);

          Serial.print("End of command (null).\n");
          clearBuffer();
        }

      case 'M':
        if (buffer == "new RAM") {
          // Allocate 512 bytes of ram to the heap
          Serial.print("Allocating 512 bytes RAM!\n");
          unsigned char* ramAllocate = new unsigned char[512];
          long ptr_to_ramAllocate = ramAllocate;
          Serial.print("Allocation done.\n");
          Serial.print(ptr_to_ramAllocate);
          Serial.print("\n");
          clearBuffer();
        }

      case 'n':
        if (buffer.startsWith("\\")) {
          Serial.print("\n");
          clearBuffer();
        }

      case 'r':
        if (buffer.startsWith("\\")) {
          Serial.print("\n");
          clearBuffer();
        }

      case 'p':
        if (buffer == "help") {
          // "help" should print a brief summary
          // of the currently supported commands.
          Serial.print("\nHelp Menu (Lab 08.2):\n");
          Serial.print("*: Clears buffer.\n");
          Serial.print("ok: Checks if aurdino is alive.\n");
          Serial.print("\\n or \\r: Adds a line of whitespace\n");
          Serial.print("A#: Checks analog ports raw data and voltage 0-5.\n");
          Serial.print("on: Turn the pin 13 debug LED on.\n");
          Serial.print("off: Turn the pin 13 debug LED off.\n");
          Serial.print("x: Print 'x' to the serial port 10000 times.\n");
          Serial.print("baud: Change the serial baud rate to 19200.\n");
          Serial.print("grüning: Print the characters in hex.\n");
          Serial.print("new RAM: Allocates 512 bytes to memory.\n");
          Serial.print("null: Read the pointer int *ptr=NULL;.\n");
          Serial.print("new array: Does assignment task.\n");
          clearBuffer();
        }

      case 'k':
        if (buffer == "ok") {
          // "ok" should print "OK"
          //  Useful for checking if the Arduino is still alive.
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

      case 'o':
        // Turns the LED on.
        if (buffer == "on") {
          pinMode(13, OUTPUT);
          digitalWrite(13, 1);
          Serial.print("LED: [ON]\n");
          clearBuffer();
        }

      case 'f':
        // Turns the LED off.
        if (buffer == "off") {
          pinMode(13, OUTPUT);
          digitalWrite(13, 0);
          Serial.print("LED: [OFF]\n");
          clearBuffer();
        }

      case 'x':
        // Print "x" to the serial port.
        if (buffer == "x") {
          int i;
          Serial.print("-----BEGIN SERIAL PORT MESSAGE-----\n");
          for (int i = 0; i < 9999; i++) {
            Serial.print("x");
          }
          Serial.print("\n-----END SERIAL PORT MESSAGE-----\n");
          clearBuffer();
        }

      case 'd':
        // Change the serial baud rate to 19200.
        if (buffer == "baud") {
          Serial.flush();
          delay(10);
          Serial.begin(19200);
          Serial.print("Are you reading this?\n");
          Serial.flush();
          delay(10);
          Serial.begin(9600);
          clearBuffer();
        }

      default:

      case 'g':
        // Test command names with Unicode chars.
        if (buffer == "grüning") {
          Serial.print("grüning\n");
          Serial.print("Print the chars in hex.\n");
          Serial.print("{");
          Serial.print(buffer);
          Serial.print("} = 0x");
          for (int i = 0; i < (int)buffer.length(); i++) {
            unsigned char hexChar = buffer[i];
            Serial.print((int)hexChar, HEX);
          }
          Serial.print("\n");
          clearBuffer();
        }
    }
  }
  delay(1000);
}
