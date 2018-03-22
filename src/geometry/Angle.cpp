//
// Created by sarcoma on 22/03/18.
//

#include "Angle.h"
#include <cmath>

void Angle::setDegrees(double degrees)
{
    this->angle = degrees;
}

void Angle::setRadians(double radians)
{
    this->angle = radiansToDegrees(radians);
}

double Angle::getDegrees()
{
    return this->angle;
}

double Angle::getRadians()
{
    return degreesToRadians(this->angle);
}

void Angle::addDegrees(double degrees)
{
    this->angle += degrees;
}

void Angle::addRadians(double radians)
{
    this->angle += radiansToDegrees(radians);
}

void Angle::subtractDegrees(double degrees)
{
    this->angle -= degrees;
}

void Angle::subtractRadians(double radians)
{
    this->angle -= radiansToDegrees(radians);
}

void Angle::multiplyBy(double value)
{
    this->angle *= value;
}

void Angle::divideBy(double value)
{
    this->angle /= value;
}

double Angle::radiansToDegrees(double radians)
{
    return radians*(180/M_PI);
}

double Angle::degreesToRadians(double degrees)
{
    return degrees*(M_PI/180);
}
