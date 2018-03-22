//
// Created by sarcoma on 22/03/18.
//

#ifndef SDLTEST_ANGLE_H
#define SDLTEST_ANGLE_H

class Angle {
private:
    double angle{};

    double radiansToDegrees(double radians);

    double degreesToRadians(double degrees);

public:
    void setDegrees(double degrees);

    void setRadians(double radians);

    double getDegrees();

    double getRadians();

    void addDegrees(double degrees);

    void addRadians(double);

    void subtractDegrees(double degrees);

    void subtractRadians(double radians);

    void multiplyBy(double value);

    void divideBy(double value);
};

#endif //SDLTEST_ANGLE_H
