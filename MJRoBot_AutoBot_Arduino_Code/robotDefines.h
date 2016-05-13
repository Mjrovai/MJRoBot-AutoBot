// *********Arduino Pin Mapping 

// Motor Drives

const int rearMtFw = 4;     // Rear Motor  - FW
const int rearMtBw = 7;     // Rear Motor  - BW
const int rearMtEne = 6;    // Rear Motor  - enable
const int frontMtLeft = 2;  // Front Motor - turn Left
const int frontMtRight = 3; // Front Motor - turn right 
const int frontMtEne = 5;   // Front Motor enable

// LEDs
const int ledBlue = 8;
const int ledRed = 12;
const int ledStatus = 13;

// Buzzer
int outBuz = 9;

// **********Definitions  

//Motor Drive
# define MAX_SPEED 220 // 70% of top speed ==> 256
# define MIN_SPEED 70 

const int ON = 1;
const int OFF = 0;
const int RIGHT = 1;
const int LEFT = 0;
const int FW = 1;
const int BW = 0;

int motorSpeed = 200;

int turnOn = false; // Robot ON/OFF Controled by Key. Star as OFF
char command = 0; // variable to store command received from IR or BT remote control

char state = 0;


