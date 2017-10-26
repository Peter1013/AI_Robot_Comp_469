//The sample code for driving one way motor encoder
const byte motor0pin = 9;//
const byte encoder0pinA = 2;//2;//A pin -> the interrupt pin 2
const byte encoder0pinB = 3;//3;//B pin -> the digital pin 3
byte encoder0PinALast;
int duration0;//the number of the pulses
boolean Direction0;//the rotation direction 


//The sample code for driving one way motor encoder
const byte motor1pin = 10;//
const byte encoder1pinA = 18;//2;//A pin -> the interrupt pin 2
const byte encoder1pinB = 19;//3;//B pin -> the digital pin 3
byte encoder1PinALast;
int duration1;//the number of the pulses
boolean Direction1;//the rotation direction 

#include <Servo.h>
Servo ST0, ST1;

void wheelSpeed0();
void wheelSpeed1();

void setup() {

  Serial.begin(9600);
  
  ST0.attach(motor0pin, 1000, 2000);
  ST1.attach(motor1pin, 1000, 2000);
  // put your setup code here, to run once:
  Direction0 = true;//default -> Forward  
  pinMode(encoder0pinB,INPUT);  
  attachInterrupt(digitalPinToInterrupt(encoder0pinA), wheelSpeed0, CHANGE);//int.on pin 

  Direction1 = true;//default -> Forward  
  pinMode(encoder1pinB,INPUT);  
  attachInterrupt(digitalPinToInterrupt(encoder1pinA), wheelSpeed1, CHANGE);//int.on pin 

  ST0.write(90);
  ST1.write(90);
  delay(1000);

  duration0 = 0;
  duration1 = 0;
  //moveForward(1000);
  Turn();
  
}

void loop() {
  // put your main code here, to run repeatedly:
}

/*
void turnLeft()
{
  ST0.write(80);
  ST1.write(110);

  while(abs(duration0) < 1334 && abs(duration1) < 1334)
}
/.*/

void Turn()
{
   ST0.write(70);
   ST1.write(110);

   while(abs(duration0) < 1334 && abs(duration1) < 1334)
   {
      delay(1);
   }

   ST0.write(90);
   ST1.write(90);
}

void moveForward(int distance) //in mm
{
  ST0.write(110);
  ST1.write(110);

  float c = (float)distance * (1334.0 / 427.25);

  while(abs(duration0) < (int)c && abs(duration1) < (int)c)
  {
    delay(1);
  }

  ST0.write(90);
  ST1.write(90);
   
  duration0 = 0;
  duration1 = 0;
}

void wheelSpeed0()
{
  int Lstate = digitalRead(encoder0pinA);
  if((encoder0PinALast == LOW) && Lstate==HIGH)
  {
    int val = digitalRead(encoder0pinB);
    if(val == LOW && Direction0)
    {
      Direction0 = false; //Reverse
    }
    else if(val == HIGH && !Direction0)
    {
      Direction0 = true;  //Forward
    }
  }
  encoder0PinALast = Lstate;
  
  if(!Direction0)  duration0++;
  else  duration0--;
}

void wheelSpeed1()
{
  int Lstate = digitalRead(encoder1pinA);
  if((encoder1PinALast == LOW) && Lstate==HIGH)
  {
    int val = digitalRead(encoder1pinB);
    if(val == LOW && Direction1)
    {
      Direction1 = false; //Reverse
    }
    else if(val == HIGH && !Direction1)
    {
      Direction1 = true;  //Forward
    }
  }
  encoder1PinALast = Lstate;
  
  if(!Direction1)  duration1++;
  else  duration1--;
}
