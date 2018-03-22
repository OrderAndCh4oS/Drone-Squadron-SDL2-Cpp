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

double Vector::getAngleRadians()
{
    return atan2(getY(), getX());
}

double Vector::getAngleDegrees()
{
    return atan2(getY(), getX())*(180/M_PI);
}

void Vector::setAngle(double radians)
{
    const double length = getLength();
    setX(cos(radians)*length);
    setY(sin(radians)*length);
}

double Vector::getLength()
{
    return sqrt(getX()*getX()+getY()*getY());
}

void Vector::setLength(double length)
{
    const double angle = getAngleRadians();
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
    const double angle = getAngleRadians();
    const double angleTwo = vector.getAngleRadians();
    return atan2(sin(angle-angleTwo), cos(angle-angleTwo));
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
