#include "Vector2D.h"
#include "Car.h"

//Right motor
#define ENB 5
#define IN1 7
#define IN2 8

//Left motor
#define IN3 9
#define IN4 11
#define ENA 6

//    The direction of the car's movement
//  ENA   ENB   IN1   IN2   IN3   IN4   Description
//  HIGH  HIGH  HIGH  LOW   LOW   HIGH  Car is runing forward
//  HIGH  HIGH  LOW   HIGH  HIGH  LOW   Car is runing back
//  HIGH  HIGH  LOW   HIGH  LOW   HIGH  Car is turning left
//  HIGH  HIGH  HIGH  LOW   HIGH  LOW   Car is turning right
//  HIGH  HIGH  LOW   LOW   LOW   LOW   Car is stoped
//  HIGH  HIGH  HIGH  HIGH  HIGH  HIGH  Car is stoped
//  LOW   LOW   N/A   N/A   N/A   N/A   Car is stoped

// PWM: https://www.arduino.cc/en/Tutorial/Foundations/PWM
// Note: The car's motors will start humming when the analog
// value/PWM wave is less than 100. Need to make sure the value
// is over 100 for the motor to turn.


//----------------------------------------------
// Setup
//----------------------------------------------
void setup()
{
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  /*
    Serial.print("IN1 = " + analogRead(IN1));
    Serial.print("IN2 = " + analogRead(IN2));
    Serial.print("IN3 = " + analogRead(IN3));
    Serial.print("IN4 = " + analogRead(IN4));
    Serial.print("ENA = " + analogRead(ENA));
    Serial.print("ENB = " + analogRead(ENB));
  */
}

//----------------------------------------------
// Forward
//----------------------------------------------
void forward()
{
  //go forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  Serial.println("Forward");
}

//----------------------------------------------
// Reverse
//----------------------------------------------
void reverse()
{
  //runing back
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  Serial.println("Reverse");
}

//----------------------------------------------
// Left
//----------------------------------------------
void left() {
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  Serial.println("Left");
}

//----------------------------------------------
// Right
//----------------------------------------------
void right() {
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  Serial.println("Right");
}

int pwmL = 100;
int pwmH = 255;

void rightAnalog() {
  analogWrite(ENA, pwmH);
  analogWrite(ENB, pwmH);
  analogWrite(IN1, pwmH);
  analogWrite(IN2, pwmL);
  analogWrite(IN3, pwmH);
  analogWrite(IN4, pwmL);

  Serial.println("Right");
}

//----------------------------------------------
// Stop
//----------------------------------------------
void stopMove()
{
  //stop
  analogWrite(ENB, 0); //speed = 0
  analogWrite(ENA, 0);

  Serial.println("Stop");
}

//----------------------------------------------
// Accelerate
//----------------------------------------------
void accelerate()
{
  //accelerate
  for (int i = 0; i <= 255; i++) {
    analogWrite(ENB, i);
    analogWrite(ENA, i);
    delay(20);
  }
}

//----------------------------------------------
// Decelerate
//----------------------------------------------
void decelerate()
{
  //reduce the speed
  for (int i = 255; i >= 0; i--) {
    analogWrite(ENB, i);
    analogWrite(ENA, i);
    delay(20);

    Serial.print("ENA = " + String(i));
    Serial.print(" ENB = " + String(i));
    Serial.print("\n");
  }
}

//----------------------------------------------
// Wander algorithm
//----------------------------------------------
void wander()
{
  Vector2D v1(5.0, 5.0);
  Vector2D v2(2.0, 2.0);
  v1.normalize();

  Serial.println("v1.x=" + String(v1.getX()));
  Serial.println("v1.x=" + String(v1.getY()));
  Serial.println("v2.x=" + String(v2.getX()));
  Serial.println("v2.x=" + String(v2.getY()));

#if 0
  Vector2D v = Vector2D::sub(v1, v2);
  Serial.println("v1.x=" + String(v.getX()));
  Serial.println("v1.x=" + String(v.getY()));
#endif

  bool isT = true;
  while (isT != false) {};
}

//----------------------------------------------
// Main
//----------------------------------------------
void loop()
{
  // forward();
  // decelerate();
  // stopMove();
  // delay(2000);
  
  Car car(IN1, IN2, IN3, IN4, ENA, ENB);
  while(true != false)
  {
    car.forward();
  }
}
