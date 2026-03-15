// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

double calculateEarthRopeGap();

struct PoolCosts {
    double concreteCost;
    double fenceCost;
    double totalCost;
};

double calculateEarthRopeGap();
PoolCosts calculatePoolCosts(double poolRadius = 3.0, 
                             double pathWidth = 1.0,
                             double concretePrice = 1000.0, 
                             double fencePrice = 2000.0);

#endif  // INCLUDE_CIRCLE_H_
