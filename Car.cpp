#include "Car.h"

Car::Car(byte in1, byte in2, byte in3, byte in4, byte ena, byte enb )
{
    this -> in1 = in1;
    this -> in2 = in2;
    this -> in3 = in3;
    this -> in4 = in4;
    this -> ena = ena;
    this -> enb = enb;

    this -> xSpeed = 0;
    this -> ySpeed = 0;
    this -> velocity = Vector2D::Vector2D(0, 0);
);

void Car::getXSpeed();
void Car::getYSpeed();
void Car::getSpeed();
void Car::getVelocity();

void Car::setXSpeed(double xspeed);
void Car::setYSpeed(double xspeed);
void Car::setVelocity(Vector2D vec);

void Car::left();
void Car::right();
void Car::forward();
void Car::reverse();
void Car::accelerate(double maxSpeed);
void Car::decelerate(double minSpeed);