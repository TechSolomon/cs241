// CS 241 Lab 2 Assignment 3: More Keys, Fewer Pins
// By: Benjamin Stream & Solomon Himelbloom

void setup() {
  Serial.begin(9600);
  pinMode(A2, INPUT);
}

void loop()

{

  /*
1 = 902 mV
2 = 1.53 V
3 = 2.50 V
A = 2.75 V
  */
  
  float v=analogRead(A2); // reads voltage on pin A2: 0 .. 1023
  float realV=5.0*v/1023.0; // scale to actual volts above ground

  /*
   In a series circuit, the current flows through
   both the top and bottom resistors, so Itop = Ibottom.
   Thus Vtop / Rtop = Vbottom / Rbottom, solve for Rbottom.
   */

  float Vbottom=realV; // A2 to GND
  float Vtop=5.0-realV;  // 5V to A2
  float Rtop=1000.0;  // top known resistance (1k)
  float Rbottom=Vbottom / (Vtop/Rtop);
  
  delay(1000); // Wait for 100 milliseconds
  
  Serial.println(Vbottom);
  
  if (Vbottom == 0.90) {
    Serial.print("Key 1 was pressed.\n");
  }
  
  else if (Vbottom == 1.53) {
    Serial.print("Key 2 was pressed.\n");
  }
  
  else if (Vbottom == 2.50) {
    Serial.print("Key 3 was pressed.\n");
  }
  
  else if (Vbottom == 2.75) {
    Serial.print("Key A was pressed.\n");
  }
  
  else {
    Serial.print("No valid keys pressed.\n");
  }
}
