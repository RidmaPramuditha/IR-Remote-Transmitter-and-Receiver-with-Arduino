#include "IRremote.h"

int IR_Receiver=7;    
int ledPin = 6;

IRrecv irrecv(IR_Receiver);         
decode_results results; 

void setup() {

  Serial.begin(9600);                         
  Serial.println("Starting Serial Monitor");  
  pinMode(ledPin, OUTPUT);
  irrecv.enableIRIn();                        
                               
}


void loop() {

  if (irrecv.decode(&results)) {                

    Serial.print(results.value, HEX);           
    Remote();                                  
  }
}

void Remote()  {                           

  switch(results.value)  {                           

  case 0xFFA25D:           
       digitalWrite(ledPin, HIGH);
       
    break;
  
  default:
       Serial.println("undefined button");

  }
    delay(50);                                       
    irrecv.resume();                                 

} 
