const int emiRx = 2;
const int emiTx = 3;

// buttons inside the hand
const int rightHand = 4;
const int leftHand = 5;

const int flexBodyFront = A0;
const int flexBodyBack = A1;

const int sensorLow = 400;
const int sensorHigh = 600;

const int ledPin = 13;

boolean negativeFeedback = false;
boolean positiveFeedback = false;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status


void setup(){

  pinMode (rightHand, INPUT);
  pinMode (leftHand, INPUT);

  pinMode (ledPin, OUTPUT);

  digitalWrite(rightHand, LOW);
  digitalWrite (leftHand, LOW);
}

void loop(){

  //buttonState = digitalRead(rightHand);


  if (digitalRead (rightHand) == HIGH || digitalRead (leftHand) == HIGH) {     
    // When either hand is pressed, do this:    
    digitalWrite(ledPin, HIGH);  
    positiveFeedback = true;
  } 
  else {
    // turn LED off, or whatever else
    digitalWrite(ledPin, LOW); 
  }

  if (positiveFeedback) {
    // select random phrase, and send it to emic
  }
}


void isNegative() {
  if (isRunning == false && (analogRead(flexBodyFront) > sensorLow || analogRead(flexBodyFront) < sensorHig)h){
    // do negative feedback
  } 


}




