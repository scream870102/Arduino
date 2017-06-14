int latchPin = 8;
int clockPin = 12;
int dataPin = 11;
int timer=0;
const int velocity =20;
byte colDataMatrix[8] = { B01111111,
                          B10111111,
                          B11011111,
                          B11101111,
                          B11110111,
                          B11111011,
                          B11111101,
                          B11111110
                        };                     
byte rowDataMatrix[8] = { B11111111,
                          B10000001,
                          B10000001,
                          B10000001,
                          B10000001,
                          B10000001,
                          B10000001,
                          B11111111
                        }; 
byte rowDataMatrix2[8] = {B00000000,
                          B01111110,
                          B01000010,
                          B01000010,
                          B01000010,
                          B01000010,
                          B01111110,
                          B00000000
                        };
byte rowDataMatrix3[8] = {B00000000,
                          B00000000,
                          B00111100,
                          B00100100,
                          B00100100,
                          B00111100,
                          B00000000,
                          B00000000
                        }; 
byte rowDataMatrix4[8] = {B00000000,
                          B00000000,
                          B00000000,
                          B00011000,
                          B00011000,
                          B00000000,
                          B00000000,
                          B00000000
                        };                                                                            

// 定義每個七段顯示器顯示的時間 (延遲時間), 預設 1ms 
int delay_time = 1;

                             
void setup() {
 pinMode(latchPin,OUTPUT);
 pinMode(clockPin,OUTPUT);
 pinMode(dataPin,OUTPUT);
}

 
void loop() {
pic(rowDataMatrix,velocity);
pic(rowDataMatrix2,velocity);
pic(rowDataMatrix3,velocity);
pic(rowDataMatrix4,velocity);
}

void pic(byte pic[],int duration){
    for(;timer<duration;timer++){
    for(int i = 0; i < 8 ; i++){
      digitalWrite(latchPin,LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
      shiftOut(dataPin, clockPin, MSBFIRST, pic[i]);
      digitalWrite(latchPin,HIGH);
      delay(delay_time);
    } 
  }
  timer=0;
}

 
 


