// list 16 pin numbers 
// start with pin 16 (15 on 6502 microprocessor) 
const char ADDR[] = {22, 24, 26, 28, 30, 32, 34, 36, 40, 42, 44, 46, 48, 50, 52};

#define CLOCK 2 

void setup() {
  for (int n=0; n<16; n += 1) {
    pinMode(ADDR[n], INPUT);
  }
  pinMode(CLOCK, INPUT); 

  attachInterrupt(digitalPinToInterrupt(CLOCK), onClock, RISING); 
  
  Serial.begin(57600); 
}

void onClock(){
  for (int n =0; n<16; n += 1) {
    int bit = digitalRead(ADDR[n]) ? 1 : 0;
    Serial.print(bit);  
  }
  Serial.println();
}

void loop() {
}
