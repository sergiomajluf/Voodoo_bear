/*

 VOODOO BEAR
 Physical Computing Midterm
 ITP - OCTOBER 2012
 
 Created by:
 Vanessa Joho, Sergio Majluf, Myriam Melki, Colin Narver
 
 */

// Includes go first
#include <SoftwareSerial.h>
#include <SimpleTimer.h>

// Setup pins for Emic 2
const rxPin 2    // Serial input, connects to Emic 2 SOUT
const txPin 3    // Serial output, connects to Emic 2 SIN

// define constants that won't change
// Rename them later when actual sensors are attached
const int sensorPinA = 4;
const int sensorPinB = 5;
const int sensorPinC = 6;
const int sensorPinD = 7


;

// Bear talking about himself
char* bearLife[]={
  "I would be truly amused if you came closer wo we could talk", 
  "I used to have a nice life, until I was left here, on my own", 
  "More phrases about my personal bear life",
  "More phrases about my personal bear life",
  "More phrases about my personal bear life",
  "More phrases about my personal bear life",
  "More phrases about my personal bear life",
  "More phrases about my personal bear life"
};

// We will append a user name to the string, so it's like
// "Tom said you wouldn't..."
char* gossipVoice[]={
  "said you wouldn't hurt me. Don't do it!", 
  "doesn't know how to hug a bear. Will you show him how it's done?", 
  "more phrases by other users",
  "more phrases by other users",
  "more phrases by other users"
};

// Once the interaction begins, the Bear will talk to the user
char* elicitingPhrases[]={
  "Wow, that's a really ugly scarf",
  "It smells like a bear died in here; and it's no me",
  "Nice",
  "",
  "",
  ""
}

// The final speech
char* endingPhrases[]={
  "I'm done with you. Move on",
  "Wow, your were really nice. Thanks for stoping by",
  "Have a great day. Goodbye!",
  "",
}
// define variables that will change

// set up a new serial port for the Emic
SoftwareSerial emicSerial =  SoftwareSerial(rxPin, txPin);

// set up a Timer to re-run the program
SimpleTimer timer;

void setup() {
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);

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

  // Timer
  timer.setInterval(1800000, repeatMe); // 3 minutes
    
}

void loop() {
  // main code here 
  timer.run();
}

/*
 In the loop, when needed, we'll pass an array item to this function,
 hopefully like sepakingBear(endingPhrases[3]);
*/

String speakingBear (String phrase){
  // Send the desired string to convert to speech
  emicSerial.print("");  
  emicSerial.print('\n');
  
  while (emicSerial.read() != ':');   // Wait here until the Emic 2 responds with a ":" indicating it's ready to accept the next command
  
}

// a function to be executed periodically
void repeatMe() {
    //Serial.print("Uptime (s): ");
    //Serial.println(millis() / 1000);

    // Code here to eval reset 
}


