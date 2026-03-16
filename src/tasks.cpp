// Copyright 2022 UNN-CS
#include "tasks.h"
#include "circle.h"
#include <cmath>

const double PI = 3.141592653589793;

double ropeGap() {
    double earthRadius = 6378.1 * 1000;

    Circle earth(earthRadius);

    double newLength = earth.getFerence() + 1;

    Circle rope(1);
    rope.setFerence(newLength);

    return rope.getRadius() - earth.getRadius();
}

double poolConcreteCost() {
    double poolRadius = 3;
    double pathWidth = 1;

    Circle pool(poolRadius);
    Circle poolWithPath(poolRadius + pathWidth);

    double pathArea = poolWithPath.getArea() - pool.getArea();

    return pathArea * 1000;
}

double poolFenceCost() {
    double poolRadius = 3;
    double pathWidth = 1;

    Circle poolWithPath(poolRadius + pathWidth);

    return poolWithPath.getFerence() * 2000;
}
