//
// Created by sarcoma on 11/03/18.
//

#ifndef SDLTEST_POINT_H
#define SDLTEST_POINT_H

class Point {
private:
    double x{};
    double y{};
public:
    double getX() const;

    void setX(int x);

    double getY() const;

    void setY(int y);

    void setX(double x);

    void setY(double y);

    void add(int x, int y);

    void subtract(int x, int y);

    void multiply(int x, int y);

    void divide(int x, int y);

    void add(double x, double y);

    void subtract(double x, double y);

    void multiply(double x, double y);

    void divide(double x, double y);
};

#endif //SDLTEST_POINT_H
