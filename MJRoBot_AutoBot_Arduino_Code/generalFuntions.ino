  
 
 void checkBTcmd()  // verify if a command is received from BT remote control
 { 
    if (BT1.available()) 
    { 
      command = BT1.read();
      BT1.flush();
    }
 }
 
 //******************************************************************************//

void manualCmd()
{
  switch (command)
  {
    case 'f': 
      moveStop(); //turn off both motors
      state = command;
      break;

    case 'w':  
      moveForward(); 
      state = command;  
      break;

    case 'd':     
      moveRight();
      break;

   case 'a': 
      moveLeft();
      break;
    
    case 's':  
      moveBackward();
      state = command;
      break;

    case '+': 
      if (state == 'w')
      {
        motorSpeed = motorSpeed + 10;
        if (motorSpeed > MAX_SPEED) 
        { 
          motorSpeed = MAX_SPEED;
        }  
        command = 'w';
      } else {command = state;}
      break;

    case '-': 
 
      if (state == 'w')
      {
        motorSpeed = motorSpeed - 10;
      }     
      if (motorSpeed < MIN_SPEED ) 
      { 
        motorSpeed = MIN_SPEED;
      }
      Serial.println(motorSpeed); 
      command = state;
      break;
  }
}
 
//******************************************************************************//    
//Beep

void beep(int pin, int freq, long ms)   //square wave - freq ==> ms
{
  int i;
  long semiper = (long) (1000000/(freq*2));
  long loops = (long)((ms*1000)/(semiper*2));
  for (i=0;i<loops;i++){
    digitalWrite(pin, HIGH);  //set buzzer pin high
    delayMicroseconds(semiper);  //for half of the period
    digitalWrite(pin, LOW);   //set buzzer pin low
    delayMicroseconds(semiper);  //for the other half of the period
    }
}

 


