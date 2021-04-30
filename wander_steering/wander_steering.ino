//--------------------------------------------------------------------------------
// Name: Jill Kapchan
// CSE 494: Intro to Robotics
// Description: This is the driver file for the car's logic.
//--------------------------------------------------------------------------------
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

// TODO: Change the value depending on the units for velocity
int CIRCLE_DISTANCE = 10;
int CIRCLE_RADIUS = 3;

// Bluetooth
#include "SoftwareSerial.h"
#define TxD 0
#define RxD 1
SoftwareSerial serial_connection(TxD, RxD);
//--------------------------------------------------------------------------------
// Setup
//--------------------------------------------------------------------------------
void setup()
{
  Serial.begin(9600);

  // Bluetooth is on a different baud rate to minimize errors
  serial_connection.begin(38400);
  serial_connection.println("Started");

  // Clear buffer
  while(serial_connection.available())
  {
    serial_connection.read();
  }
}

//--------------------------------------------------------------------------------
// Test method
//--------------------------------------------------------------------------------
void vectorTest()
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

  Vector2D v(200, 100);
  v.setAngle(0.785398);

  Serial.println(v.getX());
  Serial.println(v.getY());

  bool isT = true;
  while (isT != false) {};
}

//--------------------------------------------------------------------------------
// Attempted to project the displacement circle
// Quite hard since I don't have a true velocity (no direction)
//--------------------------------------------------------------------------------
Vector2D wander()
{
  // Calculating the circle's position
  Vector2D circleCenter(car.getX(), car.getY());
  circleCenter.normalize();
  circleCenter.mult(CIRCLE_DISTANCE);

  // Displacement force
  Vector2D displacement(0, -1);
  displacement.mult(CIRCLE_RADIUS);

  // Randomly change the vector direction by
  // making it change its current angle
  displacement.setAngle(car.getWanderAngle());
  
  // Prepare the car for the next interation
  car.updateWanderAngle();

  // Wander force
  circleCenter.add(displacement);
  return circleCenter;
}

// Check Bluetooth connections
bool receivedBluetoothSignal()
{
  byte inBytes = serial_connection.available();
  if(inBytes > 0)
  {
    serial_connection.println("Receiving data");

    // Need to clear the buffer
    while(serial_connection.available())
    {
      serial_connection.read();
    }
    return true;
  }
  else
  {
    // No bluetooth signal
    return false;
  }
}

//--------------------------------------------------------------------------------
// Main loop
//--------------------------------------------------------------------------------
void loop()
{
  Vector2D steering = wander();
  //Serial.println(steering.getX());
  //Serial.println(steering.getY());

  car.setSpeed(120);
  delay(10000);
  while(true)
  {
    // Saw an object to avoid
    if(receivedBluetoothSignal())
    {
      serial_connection.println("Received signal");
      car.stopMove();
      // Stop the car for 5 seconds
      delay(5000);
    }
    else
    {
      car.right();
    }
  }
}
