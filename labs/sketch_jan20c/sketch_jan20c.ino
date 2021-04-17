int xPin = A0;
int yPin = A1;
int xVal;
int yVal;

void setup() {
  Serial.begin(9600);
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);

}

void loop() {
  delay(200);
  Serial.print("X value: \n");
  xVal = analogRead(xPin); // read the input pin
  Serial.println(xVal);
  Serial.print("Y value: \n");
  yVal = analogRead(yPin); // read the input pin
  Serial.println(yVal);
  Serial.println(); // new line after the numbers
  
  Serial.print(xVal);
  Serial.print(",");
  Serial.println(yVal);
}
