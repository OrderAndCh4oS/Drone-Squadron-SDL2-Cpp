//
// Created by sarcoma on 11/03/18.
//

#include "Point.h"

double Point::getX() const
{
    return x;
}

void Point::setX(int x)
{
    Point::x = x;
}

void Point::setX(double x)
{
    Point::x = x;
}

double Point::getY() const
{
    return y;
}

void Point::setY(int y)
{
    Point::y = y;
}

void Point::setY(double y)
{
    Point::y = y;
}

void Point::add(int x, int y)
{
    this->x += x;
    this->y += y;
}

void Point::subtract(int x, int y)
{
    this->x -= x;
    this->y -= y;
}

void Point::multiply(int x, int y)
{
    this->x *= x;
    this->y *= y;
}

void Point::divide(int x, int y)
{
    this->x /= x;
    this->y /= y;
}

void Point::add(double x, double y)
{
    this->x += x;
    this->y += y;
}

void Point::subtract(double x, double y)
{
    this->x -= x;
    this->y -= y;
}

void Point::multiply(double x, double y)
{
    this->x *= x;
    this->y *= y;
}

void Point::divide(double x, double y)
{
    this->x /= x;
    this->y /= y;
}
