// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include "circle.h"
#include "tasks.h"
#include <cmath>
#include <stdexcept>

// Тесты для класса Circle
TEST(CircleTest, DefaultConstructor) {
    Circle c;
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, ConstructorWithRadius) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 5.0);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 25.0);
}

TEST(CircleTest, SetRadius) {
    Circle c;
    c.setRadius(3.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 3.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 3.0);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 9.0);
}

TEST(CircleTest, SetFerence) {
    Circle c;
    c.setFerence(2 * M_PI * 4.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 4.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 4.0);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 16.0);
}

TEST(CircleTest, SetArea) {
    Circle c;
    c.setArea(M_PI * 25.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 5.0);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 25.0);
}

TEST(CircleTest, NegativeRadius) {
    Circle c;
    EXPECT_THROW(c.setRadius(-1.0), std::invalid_argument);
}

TEST(CircleTest, NegativeFerence) {
    Circle c;
    EXPECT_THROW(c.setFerence(-1.0), std::invalid_argument);
}

TEST(CircleTest, NegativeArea) {
    Circle c;
    EXPECT_THROW(c.setArea(-1.0), std::invalid_argument);
}

TEST(CircleTest, IsValid) {
    Circle c(3.0);
    EXPECT_TRUE(c.isValid());
    
    c.setRadius(4.0);
    EXPECT_TRUE(c.isValid());
}

TEST(CircleTest, ZeroRadius) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

// Тесты для задачи "Земля и верёвка"
TEST(EarthRopeTest, GapCalculation) {
    double gap = calculateEarthRopeGap();
    double expectedGap = 1.0 / (2 * M_PI);
    EXPECT_NEAR(gap, expectedGap, 1e-6);
}

TEST(EarthRopeTest, GapPrecision) {
    double gap = calculateEarthRopeGap();
    double theoreticalGap = 1.0 / (2 * M_PI);
    EXPECT_NEAR(gap, theoreticalGap, 1e-10);
}

// Тесты для задачи "Бассейн"
TEST(PoolTest, StandardCalculation) {
    PoolCosts costs = calculatePoolCosts(3.0, 1.0, 1000.0, 2000.0);
    
    double pathArea = M_PI * 16.0 - M_PI * 9.0;
    double expectedConcreteCost = pathArea * 1000.0;
    double expectedFenceCost = 2 * M_PI * 4.0 * 2000.0;
    
    EXPECT_NEAR(costs.concreteCost, expectedConcreteCost, 1e-6);
    EXPECT_NEAR(costs.fenceCost, expectedFenceCost, 1e-6);
    EXPECT_NEAR(costs.totalCost, expectedConcreteCost + expectedFenceCost, 1e-6);
}

TEST(PoolTest, ZeroPathWidth) {
    PoolCosts costs = calculatePoolCosts(3.0, 0.0);
    EXPECT_DOUBLE_EQ(costs.concreteCost, 0.0);
    EXPECT_DOUBLE_EQ(costs.fenceCost, 2 * M_PI * 3.0 * 2000.0);
}

TEST(PoolTest, ZeroPoolRadius) {
    PoolCosts costs = calculatePoolCosts(0.0, 1.0);
    double expectedConcreteCost = M_PI * 1.0 * 1000.0;
    EXPECT_NEAR(costs.concreteCost, expectedConcreteCost, 1e-6);
}

TEST(PoolTest, DifferentPrices) {
    PoolCosts costs1 = calculatePoolCosts(3.0, 1.0, 1000.0, 2000.0);
    PoolCosts costs2 = calculatePoolCosts(3.0, 1.0, 2000.0, 3000.0);
    
    EXPECT_DOUBLE_EQ(costs2.concreteCost, costs1.concreteCost * 2.0);
    EXPECT_DOUBLE_EQ(costs2.fenceCost, costs1.fenceCost * 1.5);
}

TEST(PoolTest, LargeValues) {
    PoolCosts costs = calculatePoolCosts(1000.0, 10.0);
    EXPECT_TRUE(std::isfinite(costs.concreteCost));
    EXPECT_TRUE(std::isfinite(costs.fenceCost));
    EXPECT_TRUE(std::isfinite(costs.totalCost));
}

TEST(PoolTest, Scaling) {
    PoolCosts costs1 = calculatePoolCosts(3.0, 1.0);
    PoolCosts costs2 = calculatePoolCosts(6.0, 2.0);
    
    EXPECT_NEAR(costs2.concreteCost / costs1.concreteCost, 4.0, 1e-6);
    EXPECT_NEAR(costs2.fenceCost / costs1.fenceCost, 2.0, 1e-6);
}
