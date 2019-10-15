// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
String inputString = "";  
String Command = "";  // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete


// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  6;      // the number of the LED pin
const int ledPin1 =  7;
const int ledPin2 =  8; 
const int buttonPin1 = 4;  
const int buttonPin2 = 5; // the number of the pushbutton pin
// variables will change:
int buttonRight = 1;         // variable for reading the pushbuttonstatus
int buttonLeft = 1;
int buttonCenter = 1;

int EnA=3;

int EnB=11;



 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 90;    // variable to store the servo position 

int angle = 90;    // variable to store the servo position 

int delayTime=1;
int delayTimeLoop=9;
int temp=0;
String temps= "";
char buf[5];

 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
   // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);  
  pinMode(buttonPin1, INPUT);
  digitalWrite(buttonPin1, HIGH);  
  pinMode(buttonPin2, INPUT);
  digitalWrite(buttonPin2, HIGH); 
  pinMode(EnA,OUTPUT);
  pinMode(EnB,OUTPUT);
  
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);   
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  
   // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
}

int ServoLoop()
{
  
  for(int i=0;i<10;i++)
  {
    digitalWrite(ledPin, HIGH); 
    digitalWrite(ledPin1, LOW); 
    digitalWrite(ledPin2, LOW);
    angle=pos;
    for(pos = angle; pos < 180; pos += 1)
    {
      myservo.write(pos);   
      delay(delayTimeLoop);     
    } 
    
    digitalWrite(ledPin, LOW); 
    digitalWrite(ledPin1, HIGH); 
    digitalWrite(ledPin2, LOW);
    
    angle=pos;
    for(pos = angle; pos>=1; pos-=1) 
    {  
      myservo.write(pos);              
      delay(delayTimeLoop); 
    } 
  }
  return 0;
}

int right()
{
  // turn LED on:    
  digitalWrite(ledPin, HIGH); 
  digitalWrite(ledPin1, LOW); 
  digitalWrite(ledPin2, LOW);
  angle=pos;
  for(pos = angle; pos < 180; pos += 1)
  {
    myservo.write(pos);   
    delay(delayTime);     
  } 
  return 0;
  
  

}

int left()
{
  // turn LED off:
  digitalWrite(ledPin, LOW); 
  digitalWrite(ledPin1, HIGH); 
  digitalWrite(ledPin2, LOW);
  angle=pos;
  for(pos = angle; pos>=1; pos-=1) 
  {  
    myservo.write(pos);              
    delay(delayTime); 
  } 
  return 0;
  

}
 
 int center()
{
  angle=pos;
  if(angle>90)
  {
    for(pos = angle; pos>=90; pos-=1) 
    {  
      myservo.write(pos);              
      delay(delayTime); 
    } 
  }
    
    if(angle<90)
  {
    for(pos = angle; pos<=90; pos+=1) 
    {  
      myservo.write(pos);              
      delay(delayTime); 
    } 
    return 0;
 
}
}
 
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      Command=inputString;
      stringComplete = true;
      Serial.println(inputString); 
      // clear the string:
      inputString = "";
      stringComplete = false;
    } 
  }
} 
 
void loop() 
{ 
//  Command.toCharArray(buf,5);
//  //sscanf(Command,"%d %s",temp,temps);
//  if(buf[3]='D' && buf[4]=='L')
//  {
//    delayTime=int(buf[1]);
//    
//  }
  buttonRight = digitalRead(buttonPin);
  buttonLeft = digitalRead(buttonPin1);
  buttonCenter = digitalRead(buttonPin2);
  
  if (buttonRight == LOW ||Command=="RG\n"  ) 
  {     
     
    right();
    // clear the string:
    Command = "";
  } 
  
  if (buttonLeft == LOW ||Command=="LF\n"){
     
    left();
    Command = "";
  }
  
  if (buttonCenter == LOW ||Command=="CT\n"){
    // turn LED off:
    digitalWrite(ledPin, LOW); 
    digitalWrite(ledPin1, LOW); 
    digitalWrite(ledPin2, HIGH);  
    center();
    Command = "";
  }
  
  if (Command=="LP\n"){
    // turn LED off:
    digitalWrite(ledPin, LOW); 
    digitalWrite(ledPin1, LOW); 
    digitalWrite(ledPin2, HIGH);  
    ServoLoop();
    Command = "";
    
  
  }
  
  if (Command=="5DL\n"){
    // turn LED off:
    analogWrite(EnA,105);
    analogWrite(EnB,105);
    Command = "";
  }
  
  if (Command=="1DL\n"){
    // turn LED off:
    analogWrite(EnA,55);
    analogWrite(EnB,55);
    Command = "";
  }
  
  if (Command=="10DL\n"){
    // turn LED off:
    analogWrite(EnA,155);
    analogWrite(EnB,155);
    Command = "";
  }
  
  if (Command=="15DL\n"){
    // turn LED off:
    analogWrite(EnA,205);
    analogWrite(EnB,205);
    Command = "";
  }
  if (Command=="20DL\n"){
    // turn LED off:
    analogWrite(EnA,255);
    analogWrite(EnB,255);
    Command = "";
  }
  
  
  
  
  
  
} 
