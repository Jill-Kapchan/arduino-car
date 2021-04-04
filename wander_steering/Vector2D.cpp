#include "Vector2D.h"

Vector2D::Vector2D(double x, double y)
{
  this -> x = x;
  this -> y = y;
}

Vector2D::~Vector2D()
{
  Serial.println("Vector destroyed");
}

double Vector2D::getX()
{
  return x;
}

double Vector2D::getY()
{
  return y;
}

void Vector2D::setX(double x)
{
  this -> x = x;
}

void Vector2D::setY(double y)
{
  this -> y = y;
}

// sin/cos takes in RADIANS
void Vector2D::setAngle(double angle)
{
  double len = this -> magnitude();
  this -> x = cos(angle) * len;
  this -> y = sin(angle) * len;
}

void Vector2D::add(Vector2D v)
{
  x += v.x;
  y += v.y;
}

Vector2D Vector2D::sub(Vector2D v1, Vector2D v2)
{
  return Vector2D(v1.x - v2.x, v1.y - v2.y);
}

void Vector2D::mult(double scalar)
{
  x *= scalar;
  y *= scalar;
}

void Vector2D::div(double scalar)
{
  x /= scalar;
  y /= scalar;
}

void Vector2D::limit(double scalar)
{
  if (x > scalar) x = scalar;
  if (y > scalar) y = scalar;
}

double Vector2D::magnitude()
{
  return sqrt((x * x) + (y * y));
}

void Vector2D::normalize()
{
  double mag = magnitude();
  x = x / mag;
  y = y / mag;
}

// a.dot(b) = |a||b|*cos(theta)
double Vector2D::dot(Vector2D v)
{
  return x * v.x + y * v.y;
}