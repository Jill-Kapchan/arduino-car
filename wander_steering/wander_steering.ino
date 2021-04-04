#include "Vector2D.h"
#include "Car.h"

// Right motor
#define ENB 5
#define IN1 7
#define IN2 8

// Left motor
#define IN3 9
#define IN4 11
#define ENA 6

// Create a car object for car movement
Car car(IN1, IN2, IN3, IN4, ENA, ENB);

//----------------------------------------------
// Setup
//----------------------------------------------
void setup()
{
  Serial.begin(9600);
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
  Vector2D v(200, 100);
  v.setAngle(0.785398);

  Serial.println(v.getX());
  Serial.println(v.getY());
  
  //car.test();
  delay(2000);  
}
