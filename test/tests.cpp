// Copyright 2025 UNN-CS Team
#include <gtest/gtest.h>
#include "../include/circle.h"
#include "../include/tasks.h"

TEST(CircleTest, Constructor) {
    Circle c(1);
    ASSERT_NEAR(c.getRadius(), 1, 0.001);
}

TEST(CircleTest, RadiusSet) {
    Circle c(1);
    c.setRadius(2);
    ASSERT_NEAR(c.getRadius(), 2, 0.001);
}

TEST(CircleTest, FerenceCalc) {
    Circle c(1);
    ASSERT_NEAR(c.getFerence(), 6.28318, 0.001);
}

TEST(CircleTest, AreaCalc) {
    Circle c(1);
    ASSERT_NEAR(c.getArea(), 3.14159, 0.001);
}

TEST(CircleTest, SetFerence) {
    Circle c(1);
    c.setFerence(6.28318);
    ASSERT_NEAR(c.getRadius(), 1, 0.01);
}

TEST(CircleTest, SetArea) {
    Circle c(1);
    c.setArea(3.14159);
    ASSERT_NEAR(c.getRadius(), 1, 0.01);
}

TEST(CircleTest, RadiusChangeArea) {
    Circle c(2);
    ASSERT_NEAR(c.getArea(), 12.566, 0.01);
}

TEST(CircleTest, RadiusChangeFerence) {
    Circle c(2);
    ASSERT_NEAR(c.getFerence(), 12.566, 0.01);
}

TEST(CircleTest, BigRadius) {
    Circle c(100);
    ASSERT_NEAR(c.getRadius(), 100, 0.001);
}

TEST(CircleTest, SmallRadius) {
    Circle c(0.5);
    ASSERT_NEAR(c.getArea(), 0.785, 0.01);
}

TEST(CircleTest, ZeroRadius) {
    Circle c(0);
    ASSERT_EQ(c.getArea(), 0);
}

TEST(CircleTest, SetAreaLarge) {
    Circle c(1);
    c.setArea(314);
    ASSERT_NEAR(c.getRadius(), 10, 0.5);
}

TEST(CircleTest, SetFerenceLarge) {
    Circle c(1);
    c.setFerence(62.83);
    ASSERT_NEAR(c.getRadius(), 10, 0.1);
}

TEST(CircleTest, UpdateConsistency) {
    Circle c(3);
    double r = c.getRadius();
    ASSERT_NEAR(c.getArea(), 3.14159*r*r, 0.001);
}

TEST(CircleTest, DoubleUpdate) {
    Circle c(5);
    c.setRadius(10);
    ASSERT_NEAR(c.getFerence(), 62.83, 0.1);
}

TEST(TaskTest, RopeGap) {
    double gap = ropeGap();
    ASSERT_NEAR(gap, 0.159, 0.01);
}

TEST(TaskTest, PoolConcreteCost) {
    ASSERT_NEAR(poolConcreteCost(), 21991, 100);
}

TEST(TaskTest, PoolFenceCost) {
    ASSERT_NEAR(poolFenceCost(), 50265, 200);
}

TEST(TaskTest, PoolCostPositive) {
    ASSERT_GT(poolConcreteCost(), 0);
}

TEST(TaskTest, FenceCostPositive) {
    ASSERT_GT(poolFenceCost(), 0);
}
