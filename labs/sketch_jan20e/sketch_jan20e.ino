void setup() {
  Serial.begin(9600);
}

void loop()

{

  int v=analogRead(A3); // reads voltage on pin A3: 0 .. 1023
  float realV=5.0*v/1023.0; // scale to actual volts above ground

  /*
   In a series circuit, the current flows through
   both the top and bottom resistors, so Itop = Ibottom.
   Thus Vtop / Rtop = Vbottom / Rbottom, solve for Rbottom.
   */

  float Vbottom=realV; // A3 to GND
  float Vtop=5.0-realV;  // 5V to A3
  float Rtop=1000.0;  // top known resistance (1k)
  float Rbottom=Vbottom / (Vtop/Rtop);
  Serial.print(realV);
  Serial.print(" volts on A3; ");
  Serial.print(Rbottom);
  Serial.print(" ohms on bottom\n");
  delay(1000); // Wait for 100 milliseconds
}
