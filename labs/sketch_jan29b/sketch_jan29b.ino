const int nsegments = 7;

/* LEDpins[segment number] = Arduino pin number */
/*                      segments: A,B,C,D,E,F,G */

const static char LEDpins[nsegments] = {2, 3, 4, 5, 6, 7, 8};
const int npatterns = 10;

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
  /* A,B,C,D,E,F,G */

};

int patternNames[6] {0,1,2,3,4,5};

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
void showChar(int digit) {
  for (auto seg = 0; seg < nsegments; seg++) {
    digitalWrite(LEDpins[seg], patterns[digit][seg]);
    delay(1); // let segments be seen
  }
}

// Controls which digit is on.
void changeDigit(bool onLeft, bool onRight) {
  if (onRight == true) {
    digitalWrite(12, LOW); // turn on right digit
    Serial.print("RIGHT ON\n");
  }
  else if (onRight == false) {
    digitalWrite(12, HIGH); // turn off right digit
    Serial.print("RIGHT OFF\n");
  }

  if (onLeft == true) {
    digitalWrite(13, LOW); // turn on right digit
    Serial.print("RIGHT ON\n");
  }
  else if (onLeft == false) {
    digitalWrite(13, HIGH); // turn off right digit
    Serial.print("RIGHT OFF\n");
  }
}

void analogState(int xIn, int yIn) {
  // x and y axis (0 to 100)
  // origin = (50, 50)
  bool flagX = false;
  bool flagY = false;
  xIn = xIn / 10.23;
  yIn = yIn / 10.23;
  
  if (xIn >= 45 && xIn <= 55) {
    Serial.print("x = [45,55]\n");
  }

  else if (xIn > 55 && flagX == false) {
    Serial.print("x = (55,100)\n");
  }

  else if (xIn < 45 && flagX == false) {
    Serial.print("x = (0,45)\n");
  }

  if (yIn >= 45 && yIn <= 55) {
    Serial.print("y = [45,55]\n");
  }

  else if (yIn > 55 && flagY == false) {
    Serial.print("y = (55,100)\n");
  }

  else if (yIn < 45 && flagY == false) {
    Serial.print("y = (0,45)\n");
  }

}

void loop() {
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);

  analogState(xVal, yVal);

  changeDigit(true, true);
  showChar(patternNames);
}
