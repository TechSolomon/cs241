const int nsegments=7;

/* LEDpins[segment number] = Arduino pin number */
/*                      segments: A,B,C,D,E,F,G */

const static char LEDpins[nsegments]={2,3,4,5,6,7,8};

const int npatterns=6;

/* patterns[pattern number][segment number] =
        1 if that pattern lights that segment, 0 if dark. */

const static char patterns[npatterns][nsegments]={

/* A,B,C,D,E,F,G */
  {1,1,1,1,1,1,0},   // Digit 0
  {0,1,1,0,0,0,0},   // Digit 1
  {1,1,0,1,1,0,1},   // Digit 2
  {1,1,1,1,0,0,1},   // Digit 3
  {0,1,1,0,0,1,1},   // Digit 4
  {1,0,1,1,0,1,1},   // Digit 5
/* A,B,C,D,E,F,G */

};

int patternNames[6] {0,1,2,3,4,5};

void setup() {

  for (int seg=0;seg<nsegments;seg++) {

    pinMode(LEDpins[seg],OUTPUT);
    digitalWrite(LEDpins[seg],0);

  }

  pinMode(13,OUTPUT);

}

int pattern=0;

void showDigit(int digit) {

  digitalWrite(13,LOW); // turn on left digit
  for (int seg=0;seg<nsegments;seg++) {
    digitalWrite(LEDpins[seg],patterns[pattern][seg]);
  }
  delay(1000); // let segments be seen
  digitalWrite(13,HIGH); // turn off left digit

  digitalWrite(12,LOW); // turn on right digit
  for (int seg=0;seg<nsegments;seg++) {
    digitalWrite(LEDpins[seg],patterns[pattern+1][seg]);
  }
  delay(1000); // let segments be seen
  digitalWrite(12,HIGH); // turn off right digit
}


void loop() {
  
  showDigit(patternNames);

  delay(1000); // Wait for 1000 millisecond(s)

  pattern++; // advance to next pattern

  if (pattern>=npatterns) pattern=0;

}
