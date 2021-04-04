#include "Car.h"

Car::Car(byte in1, byte in2, byte in3, byte in4, byte ena, byte enb)
{
    this -> in1 = in1;
    this -> in2 = in2;
    this -> in3 = in3;
    this -> in4 = in4;

    this -> ena = ena;
    this -> enb = enb;

    this -> lSpeed = 255;
    this -> rSpeed = 255;
    this -> speed = 255;
    init();
}

Car::~Car()
{
  Serial.println("Car destroyed");
}

void Car::init()
{
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
}

//-------------------------------------------------------------
// Accessors
//-------------------------------------------------------------
int Car::getLeftSpeed()
{
  return lSpeed;
}

int Car::getRightSpeed()
{
  return rSpeed;
}

int Car::getSpeed()
{
  return speed;
}

//-------------------------------------------------------------
// Mutators
//-------------------------------------------------------------
void Car::setLeftSpeed(int lSpeed)
{
  this -> lSpeed = lSpeed;
}

void Car::setRightSpeed(int rSpeed)
{
  this -> rSpeed = rSpeed;
}

void Car::setSpeed(int speed)
{
  this -> speed = speed;
}

//-------------------------------------------------------------
//  ENA   ENB   IN1   IN2   IN3   IN4   Description
//  HIGH  HIGH  LOW   HIGH  LOW   HIGH  Car is turning left
//-------------------------------------------------------------
void Car::stopMove()
{
  //speed = 0
  analogWrite(ena, 0);
  analogWrite(enb, 0);

  Serial.println("Stop");
}

//-------------------------------------------------------------
//  ENA   ENB   IN1   IN2   IN3   IN4   Description
//  HIGH  HIGH  LOW   HIGH  LOW   HIGH  Car is turning left
//-------------------------------------------------------------
void Car::left()
{
  digitalWrite(ena, speed);
  digitalWrite(enb, speed);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  Serial.println("Left");
}

//-------------------------------------------------------------
//  ENA   ENB   IN1   IN2   IN3   IN4   Description
//  HIGH  HIGH  HIGH  LOW   HIGH  LOW   Car is turning right
//-------------------------------------------------------------
void Car::right()
{
  digitalWrite(ena, speed);
  digitalWrite(enb, speed);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  Serial.println("Right");
}

//-------------------------------------------------------------
//  ENA   ENB   IN1   IN2   IN3   IN4   Description
//  HIGH  HIGH  HIGH  LOW   LOW   HIGH  Car is runing forward
//-------------------------------------------------------------
void Car::forward()
{
  digitalWrite(ena, speed);
  digitalWrite(enb, speed);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  Serial.println("Forward");
}

//-------------------------------------------------------------
//  ENA   ENB   IN1   IN2   IN3   IN4   Description
//  HIGH  HIGH  LOW   HIGH  HIGH  LOW   Car is runing back
//-------------------------------------------------------------
void Car::reverse()
{
  digitalWrite(ena, speed);
  digitalWrite(enb, speed);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  Serial.println("Reverse");
}

void Car::accelerate()
{
  for (int i = 0; i <= 255; i++)
  {
    analogWrite(enb, i);
    analogWrite(ena, i);
    delay(20);
  }
}

void Car::decelerate()
{
  for (int i = 255; i >= 0; i--)
  {
    analogWrite(enb, i);
    analogWrite(ena, i);
    delay(20);
  }
}

void Car::test()
{ 
  digitalWrite(enb, speed);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  Serial.println("Left");
}
