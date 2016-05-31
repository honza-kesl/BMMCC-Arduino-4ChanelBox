/* For BMMCC Expansion Control of Camera Function, via DB-15 Port.
 * 4 Channel Control, Channel 4 is specifially tailored to the Audio Control of the camera
 * pressing the Up button will scroll up through the volume starting at 50%
 * pressing the Down button will scroll down through the volume starting at 50%
 * button 9 is to Mute Audio. Upcoming Functionality will include LANC and a Pot for the Volume control.
 * Written By John Kesl 2016
 */

const byte button1 = 3;
const byte button2 = A1;
const byte button3 = 4;
const byte button4 = A2;
const byte button5 = 5;
const byte button6 = A3;
const byte button7 = 6;
const byte button8 = A4;
const byte button9 = 7;
//const byte pot     = A0;
const byte led13   = 13;
const byte chan1   = 8;
const byte chan2   = 9;
const byte chan3   = 10;
const byte chan4   = 11;
byte buttonState;
//int sensorState;

void setup()
{
  pinMode(chan1,  OUTPUT);
  pinMode(chan2,  OUTPUT);
  pinMode(chan3,  OUTPUT);
  pinMode(chan4,  OUTPUT);
  pinMode(led13,  OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  pinMode(button6, INPUT);
  pinMode(button7, INPUT);
  pinMode(button8, INPUT);
  pinMode(button9, INPUT);
}

void loop()
{
  buttonState = digitalRead(button1);   // Channel 1 
  if (buttonState == HIGH)
  {
    digitalWrite(chan1, HIGH);
    delayMicroseconds(1498);
    digitalWrite(chan1, !HIGH);
    delay(22.5);
  }
  else
  {
    digitalWrite(chan1, !HIGH);
  }
  
  buttonState = digitalRead(button2);
  if (buttonState == HIGH)
  {
    digitalWrite(chan1, HIGH);
    delayMicroseconds(1488);
    digitalWrite(chan1, !HIGH);
    delay(22.5);
  }
  else
  {
    digitalWrite(chan1, !HIGH);
  }
  
  buttonState = digitalRead(button3);   // Channel 2
  if (buttonState == HIGH)
  {
    digitalWrite(chan2, HIGH);
    delayMicroseconds(1497);
    digitalWrite(chan2, !HIGH);
    delay(22.5);
  }
  else
  {
    digitalWrite(chan2, !HIGH);
  }
  
  buttonState = digitalRead(button4);
  if (buttonState == HIGH)
  {
    digitalWrite(chan2, HIGH);
    delayMicroseconds(1487);
    digitalWrite(chan2, !HIGH);
    delay(22.5);
  }
  else
  {
    digitalWrite(chan2, !HIGH);
  }
  
  buttonState = digitalRead(button5);   // Channel 3
  if (buttonState == HIGH)
  {
    digitalWrite(chan3, HIGH);
    delayMicroseconds(1496);
    digitalWrite(chan3, !HIGH);
    delay(22.5);
  }
  else
  {
    digitalWrite(chan3, !HIGH);
  }
  
  buttonState = digitalRead(button6);
  if (buttonState == HIGH)
  {
    digitalWrite(chan3, HIGH);
    delayMicroseconds(1486);
    digitalWrite(chan3, !HIGH);
    delay(22.5);
  }
  else
  {
    digitalWrite(chan3, !HIGH);
  }

  buttonState = digitalRead(button7);    // Channel 4
  for (int d=1500; d<=1999; d=d+10)
  {
    if (digitalRead(button7) == HIGH)
    {
    digitalWrite(chan4, HIGH);
    delayMicroseconds(d);
    digitalWrite(chan4, !HIGH);
    delay(128);
    }
    else if (digitalRead(button7) == !HIGH)
    break;
  }

 buttonState = digitalRead(button8);
  for (int d=1500; d>=995; d=d-10)
  {
    if (digitalRead(button8) == HIGH)
    {
    digitalWrite(chan4, HIGH);
    delayMicroseconds(d);
    digitalWrite(chan4, !HIGH);
    delay(128);
    }
    else if (digitalRead(button8) == !HIGH)
    break;
  }
     
  buttonState = digitalRead(button9);
  if (buttonState == HIGH)
  {
    digitalWrite(chan4, HIGH);
    delayMicroseconds(995);
    digitalWrite(chan4, !HIGH);
    delay(22.5);
    digitalWrite(led13, HIGH);
  }
  else
  {
    digitalWrite(chan4, !HIGH);
    digitalWrite(led13, !HIGH);
  }
}
