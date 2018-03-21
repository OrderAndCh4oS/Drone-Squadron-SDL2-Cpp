//
// Created by sarcoma on 11/03/18.
//

#include "Vector.h"
#include <cmath>

Vector::Vector(int x, int y)
{
    setX(x);
    setY(y);
}

Vector::Vector(double x, double y)
{
    setX(x);
    setY(y);
}

double Vector::getAngle()
{
    return atan2(getY(), getX());
}

void Vector::setAngle(double angle)
{
    const double length = getLength();
    setX(cos(angle)*length);
    setY(sin(angle)*length);
}

double Vector::getLength()
{
    return sqrt(getX()*getX()+getY()*getY());
}

void Vector::setLength(double length)
{
    const double angle = getAngle();
    setX(cos(angle)*length);
    setY(sin(angle)*length);
}

double Vector::getDistanceTo(Vector vector)
{
    const double dx = vector.getX()-getX(), dy = vector.getY()-getY();
    return sqrt(dx*dx+dy*dy);
}

double Vector::getAngleTo(Vector vector)
{
    return atan2(sin(getAngle()-vector.getAngle()), cos(getAngle()-vector.getAngle()));
}

Vector Vector::add(Vector vector)
{
    return {getX()+vector.getX(), getY()+vector.getY()};
}

Vector Vector::subtract(Vector vector)
{
    return {getX()-vector.getX(), getY()-vector.getY()};
}

Vector Vector::multiply(double value)
{
    return {getX()*value, getY()*value};
}

Vector Vector::divide(double value)
{
    return {getX()/value, getY()/value};
}

void Vector::addTo(Vector vector)
{
    Point::add(vector.getX(), vector.getY());
}

void Vector::subtractFrom(Vector vector)
{
    Point::subtract(vector.getX(), vector.getY());
}

void Vector::multiplyBy(Vector vector)
{
    Point::multiply(vector.getX(), vector.getY());
}

void Vector::divideBy(Vector vector)
{
    Point::divide(vector.getX(), vector.getY());
}
