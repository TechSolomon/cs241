const int nsegments = 7;

/* LEDpins[segment number] = Arduino pin number */
/*                      segments: A,B,C,D,E,F,G */

const static char LEDpins[nsegments] = {2, 3, 4, 5, 6, 7, 8};
const int npatterns = 16;

/* patterns[pattern number][segment number] =
        1 if that pattern lights that segment, 0 if dark. */

const static char patterns[npatterns][nsegments] = {

  /* A,B,C,D,E,F,G */
  {1, 1, 1, 1, 1, 1, 0}, // Digit 0
  {0, 1, 1, 0, 0, 0, 0}, // Digit 1
  {1, 1, 0, 1, 1, 0, 1}, // Digit 2
  {1, 1, 1, 1, 0, 0, 1}, // Digit 3
  {0, 1, 1, 0, 0, 1, 1}, // Digit 4
  {1, 0, 1, 1, 0, 1, 1}, // Digit 5
  {1, 0, 1, 1, 1, 1, 1}, // Digit 6
  {1, 1, 1, 0, 0, 0, 0}, // Digit 7
  {1, 1, 1, 1, 1, 1, 1}, // Digit 8
  {1, 1, 1, 1, 0, 1, 1}, // Digit 9
  {1, 1, 1, 0, 1, 1, 1}, // Digit A
  {0, 0, 1, 1, 1, 1, 1}, // Digit b
  {0, 0, 0, 1, 1, 0, 1}, // Digit c
  {0, 1, 1, 1, 1, 0, 1}, // Digit d
  {1, 0, 0, 1, 1, 1, 1}, // Digit E
  {1, 0, 0, 0, 1, 1, 1}, // Digit f
  /* A,B,C,D,E,F,G */

};

int xPin = A0;
int yPin = A1;
int xVal;
int yVal;


void setup() {

  for (int seg = 0; seg < nsegments; seg++) {
    pinMode(LEDpins[seg], OUTPUT);
    digitalWrite(LEDpins[seg], 0);
  }

  Serial.begin(9600);
  Serial.begin(9600);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);

  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);

}

int pattern = 0;

// Controls which digit in pattern matrice is shown.
void showDigit(int y) {
  int digit = 0;
  if (y >= 600) {
    if (digit == npatterns) {
      digit = 0;
    }
    else {
      digit++;
      Serial.print(y);
      Serial.print("PATTERN UP\n");
    }
    for (auto seg = 0; seg < nsegments; seg++) {
      digitalWrite(LEDpins[seg], patterns[digit][seg]);
      delay(1); // let segments be seen
    }


  } else if (y <= 300) {
    if (digit == 0) {
      digit = npatterns;
    }

    else {
      digit--;
      Serial.print(y);
      Serial.print("PATTERN DOWN\n");
    }

    for (auto seg = 0; seg < nsegments; seg++) {
      digitalWrite(LEDpins[seg], patterns[digit][seg]);
      delay(1); // let segments be seen
    }

  }
}

// Controls which digit is on.
void changeDigit(int x) {
  if (x >= 600) {
    digitalWrite(12, LOW); // turn on right digit
    digitalWrite(13, HIGH); // turn off left digit
    Serial.print("RIGHT ON\n");
  }

  else if (x <= 300) {
    digitalWrite(13, LOW); // turn on left digit
    digitalWrite(12, HIGH); // turn off right digit
    Serial.print("LEFT ON\n");
  }
}

void loop() {
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  changeDigit(xVal);
  showDigit(yVal);
}
