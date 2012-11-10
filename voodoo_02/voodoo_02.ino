#include <SoftwareSerial.h>

const int emicRx = 2;
const int emicTx = 3;

// buttons inside the hand
const int rightHand = 4;
const int leftHand = 7;

const int flexBodyFront = A0;
const int flexBodyBack = A1;

const int sensorLow = 400;
const int sensorHigh = 600;

const int ledPinRed = 13;
const int ledPinGreen = 12;

boolean negativeFeedback = false;
boolean positiveFeedback = false;
boolean isRunning = false;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int tempIndex = 0;

// Arrays

char* myStrings[]={
  "This is GREEN string 0", "This is GREEN string 1", "This is GREEN string 2",
  "This is GREEN string 4", "This is GREEN string 5","This is GREEN string 6",
  "This is GREEN string 7", "This is GREEN string 8", "This is GREEN string 9",
  "This is GREEN string 10", "This is GREEN string 11","This is GREEN string 12"};

char* notMyStrings[]={
  "This is NOT RED string 0", "This is NOT RED string 1", "This is NOT RED string 2",
  "This is NOT RED string 4", "This is NOT RED string 5", "This is NOT RED string 6"};


// set up a new serial port
SoftwareSerial emicSerial =  SoftwareSerial(emicRx, emicTx);


void setup(){

  pinMode(emicRx, INPUT);
  pinMode(emicTx, OUTPUT);

  pinMode (rightHand, INPUT);
  pinMode (leftHand, INPUT);

  pinMode (ledPinRed, OUTPUT);
  pinMode (ledPinGreen, OUTPUT);

  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinGreen, LOW);


  digitalWrite(rightHand, LOW);
  digitalWrite(leftHand, LOW);


  // set the data rate for the SoftwareSerial port
  emicSerial.begin(9600);
  Serial.begin(9600);

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

  emicSerial.print('N6');
  emicSerial.print('\n');


  emicSerial.print('V14');
  emicSerial.print('\n');

}

void loop(){

  //buttonState = digitalRead(rightHand);


  if (digitalRead (rightHand) == HIGH) {         

    digitalWrite(ledPinRed, HIGH);
    speak(notMyStrings, 7);
  } 

  else if (digitalRead (leftHand) == HIGH) {         

    digitalWrite(ledPinGreen, HIGH);
    speak(myStrings, 13);
  }

  else {
    digitalWrite(ledPinRed, LOW);
    digitalWrite(ledPinGreen, LOW);

    emicSerial.print('X');

  }


}


void speak(char** nameOfTheArray, int lengthOfTheArray ) {

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

}










