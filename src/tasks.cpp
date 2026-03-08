// Copyright 2022 UNN-CS
#include "tasks.h"
#include "circle.h"
#include <cmath>

double calculateEarthRopeGap() {
    const double EARTH_RADIUS = 6378100.0;
    Circle earth(EARTH_RADIUS);
    double earthFerence = earth.getFerence();
    double newFerence = earthFerence + 1.0;
    Circle newCircle;
    newCircle.setFerence(newFerence);
    double gap = newCircle.getRadius() - EARTH_RADIUS;
    return gap;
}

PoolCosts calculatePoolCosts(double poolRadius, double pathWidth,
                             double concretePrice, double fencePrice) {
    PoolCosts costs = {0.0, 0.0, 0.0};
    Circle pool(poolRadius);
    Circle poolWithPath(poolRadius + pathWidth);
    double pathArea = poolWithPath.getArea() - pool.getArea();
    costs.concreteCost = pathArea * concretePrice;
    double fenceLength = poolWithPath.getFerence();
    costs.fenceCost = fenceLength * fencePrice;
    costs.totalCost = costs.concreteCost + costs.fenceCost;
    return costs;
}
