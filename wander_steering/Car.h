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

// PWM: https://www.arduino.cc/en/Tutorial/Foundations/PWM
// Note: The car's motors will start humming when the analog
// value/PWM wave is less than 100. Need to make sure the value
// is over 100 for the motor to turn.


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

    int lSpeed;
    int rSpeed;

  public:
    Car(byte in1, byte in2, byte in3, byte in4, byte ena, byte enb);
    void init();
    
    // Accessors
    int getLeftSpeed();
    int getRightSpeed();
    int getSpeed();

    // Setters
    void setLeftSpeed(int lSpeed);
    void setRightSpeed(int rSpeed);
    void setSpeed(int speed);

    // Movement functions
    void stopMove();
    void left();
    void right();
    void forward();
    void reverse();
    void accelerate();
    void decelerate();

    // Analog movements
    void leftAnalog();
    void rightAnalog();
    void test();
};

#endif
