const int nsegments=7;

/* LEDpins[segment number] = Arduino pin number */
/*                      segments: A,B,C,D,E,F,G */

const static char LEDpins[nsegments]={2,3,4,5,6,7,8};

const int npatterns=16;

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
  {1,0,1,1,1,1,1},   // Digit 6 
  {1,1,1,0,0,0,0},   // Digit 7
  {1,1,1,1,1,1,1},   // Digit 8
  {1,1,1,1,0,1,1},   // Digit 9
  {1,1,1,0,1,1,1},   // Digit A 
  {0,0,1,1,1,1,1},   // Digit b
  {0,0,0,1,1,0,1},   // Digit c
  {0,1,1,1,1,0,1},   // Digit d
  {1,0,0,1,1,1,1},   // Digit E
  {1,0,0,0,1,1,1},   // Digit f
/* A,B,C,D,E,F,G */

};



void setup() {

  for (int seg=0;seg<nsegments;seg++) {

    pinMode(LEDpins[seg],OUTPUT);
    digitalWrite(LEDpins[seg],0);

  }

  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);

}


// digitalWrite(13, 0==pattern); // flash at state 0
int pattern=0;
void showDigit(int digit) {

for(int x = 0;x<500;x++){
  digitalWrite(13,LOW); // turn on left digit
  for (auto seg=0;seg<nsegments;seg++) {
    digitalWrite(LEDpins[seg],patterns[digit][seg]);
  }
  delay(1); // let segments be seen
  digitalWrite(13,HIGH); // turn off left digit

  digitalWrite(12,LOW); // turn on right digit
  for (auto seg=0;seg<nsegments;seg++) {
    digitalWrite(LEDpins[seg],patterns[digit+1][seg]);
  }
  delay(1); // let segments be seen
  digitalWrite(12,HIGH); // turn off right digit
}
}


void loop() {

  for (int i=0;i<npatterns;i++)
  {
  
  showDigit(i);
   // Wait for 1000 millisecond(s)


  }
  

}
