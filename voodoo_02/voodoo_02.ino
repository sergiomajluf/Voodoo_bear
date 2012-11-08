const int emiRx = 2;
const int emiTx = 3;

// buttons inside the hand
const int rightHand = 4;
const int lefttHand = 5;

const int flexBodyFront = A0;
const int flexBodyBack = A1;

const int sensorLow = 400;
const int sensorHigh = 600;

boolean negativeFeedback = false;
boolean positiveFeedback = false;


void setup(){

  pinMode (rightHand, INPUT);
  pinMode (leftHand, INPUT);

  digitalWrite(rightHand, LOW);
  digitalWrite (lefttHand, LOW);
}

void loop(){

  if (digitalRead (rightHand) == HIGH || digitalRead (lefttHand) == HIGH) {
    positiveFeedback = true;
  } 



}


void isNegative() {
  if (analogRead(flexBodyFront) > sensorLow || analogRead(flexBodyFront) < SensorHight){
    // do negative feedback
  } 




}

