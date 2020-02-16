#include <Servo.h> 
 
Servo panservo, tiltservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position 
char dat[20];
int tlt, pan;
void setup() 
{ 
  Serial.begin(9600);
  panservo.attach(9);
  tiltservo.attach(10);
  panservo.write(90);
  tiltservo.write(90);
} 
 
void loop() 
{ 
  for(int j=0; j<20; j++){
    dat[j] = NULL;
  }
  if(Serial.available()>=0){
    int i = 0;
    while(Serial.available()){
      dat[i] = Serial.read();
      //Serial.write(dat[i]);
      delay(2);
      i++;
    }
    //Serial.write(dat);
    //Serial.println("");
    
  }
  if(dat[0]=='t'){
      tlt = ((int)dat[5]-48)*1+((int)dat[4]-48)*10+((int)dat[3]-48)*100;
      Serial.print(tlt);
      Serial.println("");
      tiltservo.write(tlt);
    }
    if(dat[0]=='p'){
      pan = ((int)dat[5]-48)*1+((int)dat[4]-48)*10+((int)dat[3]-48)*100;
      Serial.print(pan);
      Serial.println("");
      panservo.write(pan);
    }
}
