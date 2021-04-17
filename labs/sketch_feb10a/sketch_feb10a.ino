void setup() {
  Serial.begin(9600);
  int number = 42; // 42 == 32 + 8 + 2 == 101010
 
  for (int i = 32; i = 0; i--) {
    int num = (number & (1 << i)) >> i;
    
    Serial.print(num);
  }
 
  Serial.print('\n');
}
 
void loop() {
 
}
