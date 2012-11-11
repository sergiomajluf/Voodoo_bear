#include <SoftwareSerial.h>

const int emicRx = 2;
const int emicTx = 3;

const int ledPinRed=13; // Most Arduino boards have an on-board LED on this pin
const int ledPinGreen=12;


// buttons inside the hand
const int rightHand = 4;
const int leftHand = 7;

//Hall sensors
const int hallSensor = 8;

//Analog
const int flexBodyFront = A0;
const int flexBodyBack = A1;

const int sensorLow = 400;
const int sensorHigh = 600;

boolean brushing = false;
boolean negativeFeedback = false;
boolean positiveFeedback = false;
//boolean isRunning = false;

char* myStrings[]={
  "This is GREEN string 0", "This is GREEN string 1", "This is GREEN string 2",
  "This is GREEN string 4", "This is GREEN string 5","This is GREEN string 6",
  "This is GREEN string 7", "This is GREEN string 8", "This is GREEN string 9",
  "This is GREEN string 10", "This is GREEN string 11","This is GREEN string 12"};

char* notMyStrings[]={
  "This is NOT RED string 0", "This is NOT RED string 1", "This is NOT RED string 2",
  "This is NOT RED string 4", "This is NOT RED string 5", "This is NOT RED string 6"};

char* brushingPhrases[]={
  "This is a brushing phrase 0", "This is a brushing phrase 1", "This is a brushing phrase 2",
  "This is a brushing phrase 3", "This is a brushing phrase 4"};

// set up a new serial port
SoftwareSerial emicSerial =  SoftwareSerial(emicRx, emicTx);

void setup(){

  pinMode(emicRx, INPUT);
  pinMode(emicTx, OUTPUT);

  //Hall sensors
  pinMode (hallSensor, INPUT);

  pinMode (rightHand, INPUT);
  pinMode (leftHand, INPUT);
  digitalWrite(rightHand, LOW);
  digitalWrite (leftHand, LOW);

  // initialize the digital pin as an output.
  pinMode(ledPinRed, OUTPUT);     
  pinMode(ledPinGreen, OUTPUT);     

  // set the data rate for the SoftwareSerial port
  emicSerial.begin(9600);
  Serial.begin(9600);

  digitalWrite(ledPinRed, LOW);  // turn LED off
  digitalWrite(ledPinGreen, LOW); 

  /*
   When the Emic 2 powers on, it takes about 3 seconds for it to successfully
   intialize. It then sends a ":" character to indicate it's ready to accept
   commands. If the Emic 2 is already initialized, a CR will also cause it
   to send a ":"
   */
  emicSerial.print('\n');             // Send a CR in case the system is already up
  while (emicSerial.read() != ':');   // When the Emic 2 has initialized and is ready, it will send a single ':' character, so wait here until we receive it
  delay(10);                          // Short delay
  emicSerial.flush();                 // Flush the receive buffer

}

void loop(){


  if (digitalRead (rightHand) == HIGH) {         
    digitalWrite(ledPinRed, HIGH);
    speak(notMyStrings, 7, 2);
  } 

  else if (digitalRead (leftHand) == HIGH) {         
    digitalWrite(ledPinGreen, HIGH);
    speak(myStrings, 13, 2);
  }

  else {
    digitalWrite(ledPinRed, LOW);
    digitalWrite(ledPinGreen, LOW);
  }

  if (analogRead(flexBodyFront) > sensorLow && analogRead(flexBodyFront) < sensorHigh){
    speak(myStrings, 13, 1);
    //negativeFeedback = true; 
  }

  if ((analogRead(flexBodyFront) > sensorLow && analogRead(flexBodyFront) < sensorHigh) && (analogRead(flexBodyBack) > sensorLow && analogRead(flexBodyBack) < sensorHigh)){
    speak(notMyStrings, 7, 1);
  }
  //positiveFeedback = true;


  emicSerial.print('X');

}


void speak(char** nameOfTheArray, int lengthOfTheArray, int statusCheck) {

  int randnumber = random(lengthOfTheArray);

  Serial.print("arrayLength is: ");
  Serial.print(lengthOfTheArray);
  Serial.print("\t");
  Serial.print("random is: \t");
  Serial.println(randnumber);
  emicSerial.print('S');
  emicSerial.print(nameOfTheArray[randnumber]);
  emicSerial.print('\n');
  while (emicSerial.read() != ':');   // Wait here until the Emic 2 responds with a ":" indicating it's ready to accept the next command
  if(statusCheck==1){
  }
  else if(statusCheck==2){
  }
  else if(statusCheck==3){
    brushing=false;
  }
}
void brushResponse(){
  brushing=true;
  delay(1000);
  speak(brushingPhrases, 5, 3);

} 

void sensorCheck(){
  if(digitalRead (hallSensor)==HIGH && brushing==false) {  
    brushResponse();
  }

  else if(digitalRead (hallSensor)==HIGH && brushing==true) {

  }

  else if(digitalRead (hallSensor)==LOW && brushing==false) {  

  }

}










