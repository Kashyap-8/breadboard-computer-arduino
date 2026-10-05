// list 16 pin numbers 
// start with pin 16 (15 on 6502 microprocessor) 
const char ADDR[] = {22, 24, 26, 28, 30, 32, 34, 36, 40, 42, 44, 46, 48, 50, 52};

void setup() {
  for (int n=0; n<16; n += 1) {
    pinMode(ADDR[n], INPUT);
  }
  Serial.begin(57600); 
}

void loop() {
  // put your main code here, to run repeatedly(loop function):
  for (int n =0; n<16; n += 1) {
    //digiral read returns a boolean if conditon is true or false
    int bit = digitalRead(ADDR[n]) ? 1 : 0;
    Serial.print(bit);  
  }
  Serial.println();
}
