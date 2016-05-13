

void moveStop() //turn off rear motor
{ 
  analogWrite(rearMtEne, LOW);
  digitalWrite(rearMtFw, LOW);
  digitalWrite(rearMtBw, LOW);
  
  digitalWrite(frontMtEne, LOW);
  digitalWrite(ledRed, LOW);
  delay(5);
}

//******************************************************************************//  

void moveForward() // rear motor FW
{ 
  analogWrite(rearMtEne, motorSpeed);
  digitalWrite(rearMtFw, HIGH);
  digitalWrite(rearMtBw, LOW);
  
  digitalWrite(frontMtEne, LOW);
  digitalWrite(ledRed, LOW);
  delay(5);
}

//******************************************************************************//  

void moveBackward() // rear motor BW
{ 
  analogWrite(rearMtEne, motorSpeed);
  digitalWrite(rearMtFw, LOW);
  digitalWrite(rearMtBw, HIGH);
  
  digitalWrite(frontMtEne, LOW);
  digitalWrite(ledRed, HIGH);
  delay(5);
}

//******************************************************************************//  

void moveLeft() // front motor left
{ 
  digitalWrite(frontMtEne, HIGH);
  digitalWrite(frontMtLeft, HIGH);
  digitalWrite(frontMtRight, LOW);
  digitalWrite(ledRed, LOW);
  delay(10);
}

//******************************************************************************//  

void moveRight() // front motor right
{ 
  digitalWrite(frontMtEne, HIGH);
  digitalWrite(frontMtLeft, LOW);
  digitalWrite(frontMtRight, HIGH);
  digitalWrite(ledRed, LOW);
  delay(10);
}

//******************************************************************************//  

void stopRobot ()
{
  digitalWrite(ledBlue, LOW);
  digitalWrite(ledRed, LOW);
  
  state = 0;
  moveStop(); //turn off both motors
}


