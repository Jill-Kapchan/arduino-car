//--------------------------------------------------------------------------------
// Name: Jill Kapchan
// CSE 494: Intro to Robotics
// Description: This header file contains all the method prototypes for forward
//              declarations of the class Vector2D.cpp
//--------------------------------------------------------------------------------

#ifndef VECTOR_2D_H
#define VECTOR_2D_H

#include <Arduino.h>

class Vector2D
{
  private:
    double x;
    double y;
    
  public:
    Vector2D(double x, double y);
    ~Vector2D();
    
    double getX();
    double getY();

    void setX(double x);
    void setY(double y);
    void setAngle(double angle);

    void add(Vector2D v);
    static Vector2D sub(Vector2D v1, Vector2D v2);
    void mult(double scalar);
    void div(double scalar);
    void limit(double scalar);
    double magnitude();
    void normalize();
    double dot(Vector2D v);
};

#endif
