// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#include <cstdint>

class Circle {
private:
    double radius;
    double ference;
    double area;

    static const double PI;

public:
    Circle(double r = 0.0);

    void setRadius(double r);
    void setFerence(double f);
    void setArea(double a);

    double getRadius() const;
    double getFerence() const;
    double getArea() const;

    bool isValid() const;
};

#endif  // INCLUDE_CIRCLE_H_
