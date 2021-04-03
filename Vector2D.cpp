#include "Vector2D.h"

Vector2D::Vector2D(double x, double y) {
  this -> x = x;
  this -> y = y;
}

double Vector2D::getX()
{
  return this->x;
}

double Vector2D::getY()
{
  return this->y;
}

void Vector2D::add(Vector2D v) {
  this -> x += v.x;
  this -> y += v.y;
}

Vector2D Vector2D::sub(Vector2D v1, Vector2D v2) {
  return Vector2D(v1.x - v2.x, v1.y - v2.y);
}

void Vector2D::mult(double scalar) {
  this -> x *= scalar;
  this -> y *= scalar;
}

void Vector2D::div(double scalar) {
  this -> x /= scalar;
  this -> y /= scalar;
}

void Vector2D::limit(double scalar) {
  if (this -> x > scalar) this -> x = scalar;
  if (this -> y > scalar) this -> y = scalar;
}

double Vector2D::magnitude() {
  return sqrt((this -> x * this -> x) + (this -> y * this -> y));
}

void Vector2D::normalize() {
  double magnitude = this -> magnitude();
  this -> x = this -> x / magnitude;
  this -> y = this -> y / magnitude;
}

// a.dot(b) = |a||b|*cos(theta)
double Vector2D::dot(Vector2D v) {
  return this -> x * v.x + this -> y * v.y;
}
