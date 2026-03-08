// Copyright 2022 UNN-CS
#include "circle.h"
#include <cmath>
#include <stdexcept>

const double Circle::PI = 3.14159265358979323846;

Circle::Circle(double r) {
    setRadius(r);
}

void Circle::setRadius(double r) {
    if (r < 0) {
        throw std::invalid_argument("Radius cannot be negative");
    }
    radius = r;
    ference = 2 * PI * r;
    area = PI * r * r;
}

void Circle::setFerence(double f) {
    if (f < 0) {
        throw std::invalid_argument("Ference cannot be negative");
    }
    ference = f;
    radius = f / (2 * PI);
    area = PI * radius * radius;
}

void Circle::setArea(double a) {
    if (a < 0) {
        throw std::invalid_argument("Area cannot be negative");
    }
    area = a;
    radius = std::sqrt(a / PI);
    ference = 2 * PI * radius;
}

double Circle::getRadius() const {
    return radius;
}

double Circle::getFerence() const {
    return ference;
}

double Circle::getArea() const {
    return area;
}

bool Circle::isValid() const {
    const double EPSILON = 1e-10;

    double calculatedFerence = 2 * PI * radius;
    if (std::abs(calculatedFerence - ference) > EPSILON) {
        return false;
    }

    double calculatedArea = PI * radius * radius;
    if (std::abs(calculatedArea - area) > EPSILON) {
        return false;
    }

    return true;
}
