const int PIN=0;
const int LEDNUM=10;
const int MODE=2;
const int TIMER=100;
int ledPins[]={2,3,4,5,6,7,8,9,10,11};

void setup() {
  // put your setup code here, to run once:
   for (int thisLed = 0; thisLed < LEDNUM; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  int sensorRead=analogRead(PIN);
  int ledMode=map(sensorRead, 0, 1023, 0, MODE);
  if(ledMode==0){
      for (int thisLed = 0; thisLed < LEDNUM/2; thisLed++) {
        digitalWrite(ledPins[thisLed], HIGH);
        digitalWrite(ledPins[LEDNUM-thisLed], HIGH);
        delay(TIMER);
        digitalWrite(ledPins[thisLed], LOW);
        digitalWrite(ledPins[LEDNUM-thisLed], LOW);
       }
  }
  else if (ledMode==1){
        for (int thisLed = 1; thisLed < 3; thisLed++) {
          for(int ledNum=0;ledNum<LEDNUM/2;ledNum++){
              digitalWrite(ledPins[thisLed*ledNum], HIGH);
              delay(TIMER/2);
              digitalWrite(ledPins[thisLed*ledNum], LOW);
          }
       }  
  }

}
