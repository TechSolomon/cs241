int xPin = A0;
int yPin = A1;
int xVal;
int yVal;

void setup()
{
  Serial.begin(9600);
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}

void loop()
{
  delay(200);
  yVal = analogRead(yPin)/1023;  // read the input pin
  xVal = analogRead(xPin)/1023;  // read the input pin
  Serial.print(xVal);
  Serial.print(",");
  Serial.println(yVal);


}
