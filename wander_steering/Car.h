#ifndef CAR_H
#define CAR_H

#include <Arduino.h>

//    The direction of the car's movement
//  ENA   ENB   IN1   IN2   IN3   IN4   Description
//  HIGH  HIGH  HIGH  LOW   LOW   HIGH  Car is runing forward
//  HIGH  HIGH  LOW   HIGH  HIGH  LOW   Car is runing back
//  HIGH  HIGH  LOW   HIGH  LOW   HIGH  Car is turning left
//  HIGH  HIGH  HIGH  LOW   HIGH  LOW   Car is turning right
//  HIGH  HIGH  LOW   LOW   LOW   LOW   Car is stoped
//  HIGH  HIGH  HIGH  HIGH  HIGH  HIGH  Car is stoped
//  LOW   LOW   N/A   N/A   N/A   N/A   Car is stoped

class Car
{
  private:
    byte in1;
    byte in2;
    byte in3;
    byte in4;

    // Car speed is controlled by ENA and ENB
    byte ena;
    byte enb;

    int xSpeed;
    int ySpeed;

  public:
    Car(byte in1, byte in2, byte in3, byte in4, byte ena, byte enb);
    void init();
    
    // Accessors
    int getXSpeed();
    int getYSpeed();
    int getSpeed();

    // Setters
    void setXSpeed(double xspeed);
    void setYSpeed(double xspeed);

    // Movement functions
    void stop();
    void left();
    void right();
    void forward();
    void reverse();
    void accelerate(double maxSpeed);
    void decelerate(double minSpeed);
};

#endif
