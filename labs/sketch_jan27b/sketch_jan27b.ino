const int nsegments=7;
/* LEDpins[segment number] = Arduino pin number */
/*                      segments: A,B,C,D,E,F,G */
const static char LEDpins[nsegments]={2,3,4,5,6,7,8};

void setup()
{
  for (int seg=0;seg<nsegments;seg++) {
    pinMode(LEDpins[seg],OUTPUT);
    digitalWrite(LEDpins[seg],0);
  }
  pinMode(13,OUTPUT);
}

int segment=0;
void loop()
{
  digitalWrite(13,0==segment); // flash at segment 0
  for (int seg=0;seg<nsegments;seg++) {
    digitalWrite(LEDpins[seg],seg==segment);
  }
  delay(1000); // Wait for 1000 millisecond(s)
  
  segment++; // advance to next segment
  if (segment>=nsegments) segment=0;
}
