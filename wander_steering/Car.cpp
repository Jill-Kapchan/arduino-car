#include "Car.h"

Car::Car(byte in1, byte in2, byte in3, byte in4, byte ena, byte enb)
{
    this -> in1 = in1;
    this -> in2 = in2;
    this -> in3 = in3;
    this -> in4 = in4;

    this -> ena = ena;
    this -> enb = enb;

    this -> xSpeed = 0;
    this -> ySpeed = 0;

    init();
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

int Car::getXSpeed()
{
    return xSpeed;
};

int Car::getYSpeed()
{
    return ySpeed;
};

int Car::getSpeed()
{
    // Calculate speed
}

void Car::setXSpeed(double xSpeed)
{
    this -> xSpeed = xSpeed;
}

void Car::setYSpeed(double ySpeed)
{
    this -> ySpeed = ySpeed;
}

void Car::stop()
{
  analogWrite(ena, 0); //speed = 0
  analogWrite(enb, 0);

  Serial.println("Stop");
}

void Car::left()
{
  digitalWrite(ena, HIGH);
  digitalWrite(enb, HIGH);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  Serial.println("Left");
}

void Car::right()
{
  digitalWrite(ena, HIGH);
  digitalWrite(enb, HIGH);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  Serial.println("Right");
}

void Car::forward()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in3, HIGH);

  Serial.println("Forward");
}

void Car::reverse()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  Serial.println("Reverse");
}

void Car::accelerate(double maxSpeed)
{
  for (int i = 0; i <= 255; i++)
  {
    analogWrite(enb, i);
    analogWrite(ena, i);
    delay(20);
  }
}

void Car::decelerate(double minSpeed)
{
  for (int i = 255; i >= 0; i--)
  {
    analogWrite(enb, i);
    analogWrite(ena, i);
    delay(20);
  }
}
