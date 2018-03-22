//
// Created by sarcoma on 11/03/18.
//

#ifndef SDLTEST_VECTOR_H
#define SDLTEST_VECTOR_H

#include "Point.h"

class Vector : public Point {
public:
    Vector(int x, int y);

    Vector(double x, double y);

    double getAngleRadians();

    double getAngleDegrees();

    void setAngle(double radians);

    double getLength();

    void setLength(double length);

    double getDistanceTo(Vector vector);

    double getAngleTo(Vector vector);

    Vector add(Vector vector);

    Vector subtract(Vector vector);

    Vector multiply(double value);

    Vector divide(double value);

    void addTo(Vector vector);

    void subtractFrom(Vector vector);

    void multiplyBy(Vector vector);

    void divideBy(Vector vector);

};

#endif //SDLTEST_VECTOR_H
