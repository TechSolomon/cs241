// Benjamin Stream & Solomon Himelbloom
// Assignment 2

void setup() {
  Serial.begin(9600);
  Serial.print("Ready for commands (v2.0)\n");
  Serial.print("*: Clears buffer.\n");
  Serial.print("help: Opens the help menu.\n");
  randomSeed(512);
}

String buffer;

// Global variables
int Garr[10] = {0};
char *Gstr = "gello\n";
String statement = "Scrambled ";

// Autoclears Buffer
void clearBuffer() {
  buffer = "";
}

void corruptMemory(void *startPointer, int nBytes, long bitErrorRate) {
  const unsigned long megaMask = 0xFFFFF; // == 20 set bits, approx 1 million
  unsigned char *start = (unsigned char *)startPointer;
  for (int i = 0; i < nBytes; i++)
    for (unsigned int bit = 0; bit < 8; bit++)
      if ((random()&megaMask) < bitErrorRate)
        start[i] ^= (1 << bit); // flip this bit
}

void loop() {

  while (Serial.available()) {
    char c = Serial.read();
    buffer += c;
    switch (c) {
      // Manual Buffer Clear if it gets cluttered
      case '*':
        Serial.print("Clearing Buffer...\n");
        Serial.print("Current Buffer:" + buffer + "\n");
        clearBuffer();
        Serial.print("Buffer Cleared!\n");
      default:

      case 'p':
        if (buffer == "help") {
          // "help" should print a brief summary
          // of the currently supported commands.
          Serial.print("\nHelp Menu (Lab 09.2):\n");
          Serial.print("*: Clears buffer.\n");
          Serial.print("localString: Tests corrupting local strings\n");
          Serial.print("globalString: Tests corrupting global strings\n");
          Serial.print("localArray: Tests corrupting local Array\n");;
          Serial.print("globalArray: Tests corrupting global Array\n");
          Serial.print("globalVar: Tests corrupting global variables\n");
          Serial.print("stackVar: Tests corrupting the stack \n");
          clearBuffer();
        }

      case 'g':
        if (buffer == "localString") {
          for (int i = 0; i < 1000; i++) {
            char *Lstr = "hello\n";
            corruptMemory(*Lstr, 7, random(10000, 20000));
            Serial.println(*Lstr);
            clearBuffer();
          }
        }

        if (buffer == "globalString") {
          for (int i = 0; i < 1000; i++) {
            corruptMemory(*Gstr, 7, random(10000, 20000));
            Serial.println(*Gstr);
            clearBuffer();
          }
        }

      case 'y':
        if (buffer == "localArray") {
          for (int i = 0; i < 1000; i++) {
            int Larr[10] = {0};
            corruptMemory(*Larr, sizeof(Larr), random(10000, 20000));
            Serial.println(*Larr);
            clearBuffer();
          }
        }

        if (buffer == "globalArray") {
          for (int i = 0; i < 1000; i++) {
            corruptMemory(*Garr, sizeof(Garr), random(10000, 20000));
            Serial.println(*Garr);
            clearBuffer();
          }
        }

      case 'r':
        if (buffer == "globalVar") {
          corruptMemory(256, 300, random(10000, 20000));
          Serial.println(statement + buffer);
          clearBuffer();
        }

      case 'k':
        if (buffer == "stackVar") {
          corruptMemory(2000, 300, random(10000, 20000));
          Serial.println(statement + buffer);
          clearBuffer();
        }
    }
  }
  delay(250);
}
