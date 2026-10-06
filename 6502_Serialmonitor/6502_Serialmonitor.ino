// list 16 pin numbers 
// start with pin 16 (15 on 6502 microprocessor) 
const char ADDR[] = {22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52};
const char DATA[] = {53, 51, 49, 47, 45, 43, 41, 39};

#define CLOCK 2 
#define READ_WRITE 3 

void setup() {
  //Address pins
  for (int n=0; n<16; n += 1) {
    pinMode(ADDR[n], INPUT);
  }
  //Data pins 
  for (int n=0; n<8; n += 1) {
    pinMode(DATA[n], INPUT);
  }
  pinMode(CLOCK, INPUT);
  pinMode(READ_WRITE, INPUT); 

  attachInterrupt(digitalPinToInterrupt(CLOCK), onClock, RISING); 
  
  Serial.begin(57600); 
}

void onClock(){
  char output[15];

  unsigned int address = 0; 
  
  for (int n =0; n<16; n += 1) {
    int bit = digitalRead(ADDR[n]) ? 1 : 0;
    Serial.print(bit); 

    //shift the bit to make it easier to read
    address = (address << 1) + bit;  
  }

  Serial.print("   ");

  unsigned int data = 0; 
  
  for (int n =0; n<8; n += 1) {
    int bit = digitalRead(DATA[n]) ? 1 : 0;
    Serial.print(bit);
    data = (data << 1) + bit; 
  }
  // print in hex 
  sprintf(output, "  %04x %c %02x", address, digitalRead(READ_WRITE) ? 'r' : 'w', data); 
  Serial.println(output);
}

void loop() {
}
