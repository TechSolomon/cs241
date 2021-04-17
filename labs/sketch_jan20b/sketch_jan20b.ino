void setup()

{
  Serial.begin(9600);
}

void loop()

{

  int v=analogRead(A0); // reads voltage on pin A0: 0 .. 1023
  float realV=5.0*v/1023.0; // scale to actual volts above ground

  /*
   In a series circuit, the current flows through
   both the top and bottom resistors, so Itop = Ibottom.
   Thus Vtop / Rtop = Vbottom / Rbottom, solve for Rbottom.
   */

  float Vbottom=realV; // A0 to GND
  float Vtop=5.0-realV;  // 5V to A0
  float Rtop=1000.0;  // top known resistance (1k)
  float Rbottom=Vbottom / (Vtop/Rtop);
  Serial.print(realV);
  Serial.print(" volts on A0; ");
  Serial.print(Rbottom);
  Serial.print(" ohms on bottom\n");
  delay(1000); // Wait for 100 milliseconds
}
