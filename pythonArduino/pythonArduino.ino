int i = 0;
#define leduno 2
#define leddos 3
#define ledtres 4
#define ledcuatro 7
#define ledsinco 8
#define ledseis 9

#define motor 13

#define mot 5
#define mot1 6
 
#include <Servo.h>
Servo myservo;
Servo myservo1;
int pos = 0;

//Serial Event
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

// the setup routine runs once when you press reset:
void setup() {    
  Serial.begin(9600);
  inputString.reserve(200);
  for (i=2; i<=13; i++){
       pinMode(i, OUTPUT);        
  }
  myservo.attach(10);
  myservo1.attach(11);
  myservo1.write(0);
  myservo.write(0);
}
 
// the loop routine runs over and over again forever:
void loop() {
   if (stringComplete) {
    Serial.print(inputString);
    String in = inputString; 
    if(inputString == "Leds2"){
        digitalWrite(leduno, HIGH);
    }
    if(in == "Leds3"){
        digitalWrite(leddos, HIGH);
        
    }
    
    if(in == "Leds4"){
        digitalWrite(ledtres, HIGH);
        
    }
    
    if(in == "Leds7"){
        digitalWrite(ledcuatro, HIGH);
        
    }
    
    if(in == "Leds8"){
        digitalWrite(ledsinco, HIGH);
        
    }
    
    if(in == "Leds9"){
        digitalWrite(ledseis, HIGH);
        
    }
    
    if(in == "OnLeds2"){
        digitalWrite(leduno, LOW);
        
       
    }
     
    if(in == "OnLeds3"){
        digitalWrite(leddos, LOW);
        
    }
    
    if(in == "OnLeds4"){
        digitalWrite(ledtres, LOW);
        
    }
    
    if(in == "OnLeds7"){
        digitalWrite(ledcuatro, LOW);
        
    }
    
    if(in == "OnLeds8"){
        digitalWrite(ledsinco, LOW);
        
    }
    
    if(in == "OnLeds9"){
        digitalWrite(ledseis, LOW);
        
    }
   if(in == "GirarMotorIzqr"){
    digitalWrite(3,255);
    analogWrite(mot,HIGH);
    analogWrite(mot1,LOW);
  
        
    }
    if(in =="FrenarMotorIzq"){
        digitalWrite(3,0);
    }
    
    if(in == "GirarMotorDer"){
    digitalWrite(3,255);
    analogWrite(mot,LOW);
    analogWrite(mot1,HIGH);
  
        
    }
    if(in == "FrenarMotorDer"){
        digitalWrite(3,0);
    }
    
    if(in == "Bocina"){
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
    }
    
    if (in == "Interruptores"){
      Serial.flush();
      Serial.write(0x0d);
      if(digitalRead(10)==HIGH){
        Serial.write("10");
      }
      if(digitalRead(11)==HIGH){
        Serial.write("11");
      }
      if(digitalRead(12)==HIGH){
        Serial.write("12");
      }
    }
    
    if(in == "girarServo11"){
        for(pos = 10; pos <= 150; pos += 1) 
          {                                  
            myservo.write(pos);               
            delay(15);                       
          } 
          delay(500);
          for(pos = 150; pos>=10; pos-=1)      
          {                                
            myservo.write(pos);              
            delay(15);                        
          } 
          myservo.write(0);
            }
    if(in == "girarServo10"){
        for(pos = 10; pos <= 150; pos += 1) 
          {                                  
            myservo1.write(pos);               
            delay(15);                       
          } 
          delay(500);
          for(pos = 150; pos>=10; pos-=1)      
          {                                
            myservo1.write(pos);              
            delay(15);                        
          } 
          myservo1.write(0);
    }
    
    inputString = "";
    stringComplete = false;
  }
   
    
  
}
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    if (inChar == '\n') {
      
      stringComplete = true;
    } else { 
    inputString += inChar;
    }
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    
  }
}
