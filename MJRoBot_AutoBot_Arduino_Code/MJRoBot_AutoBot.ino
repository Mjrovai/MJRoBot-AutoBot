
//***********************************************************
//  MJRoBot - AutoBot (Bluetooth CMD) V1
//   
// ==>  BT remote control manual operation via Android app (MJRobot BT Remote Control)
//
// Marcelo José Rovai
// 7 May 16
//************************************************************


#include "robotDefines.h"

// BT Module
#include <SoftwareSerial.h>
SoftwareSerial BT1(10, 11); // El pin 10 es Rx y el pin 11 es Tx

//******************************************************************************//  
void setup() {

  Serial.begin(9600);
  BT1.begin(9600);
  
  // Motor Drives

  pinMode(rearMtEne, OUTPUT);
  pinMode(rearMtFw, OUTPUT);
  pinMode(rearMtBw, OUTPUT);
  pinMode(frontMtEne, OUTPUT);
  pinMode(frontMtLeft, OUTPUT);
  pinMode(frontMtRight, OUTPUT);

  //LEDs
  pinMode(ledBlue, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledStatus, OUTPUT);
  
  //Buzzer
  pinMode(outBuz, OUTPUT);
 
  //*********Initial Settings

  //motor off
  moveStop(); 

  BT1.print("MJRoBot AutoBot BT Remote Control");
  BT1.println('\n');

}


//******************************************************************************//  
void loop() 
{
  checkBTcmd();  // verify if a comand is received from BT remote control
  receiveCmd ();
  
  if (turnOn) manualCmd ();
   else stopRobot ();
}

//******************************************************************************//  

void receiveCmd ()
{
  
  switch (command)
  {
    case 'p': 
      Serial.println("command ==> p"); 
      turnOn = !turnOn;
      command = 0;
      analogWrite(ledStatus, turnOn*128); // Robot ON - Led ON
      beep(outBuz, 1000, 100);
      BT1.print(" COMMAND ON/OFF");
      BT1.println('\n');
      delay(200); //Delay to call attention to mode change
      break;
      
   case 'm': //not used here
      break;
  }   
}


