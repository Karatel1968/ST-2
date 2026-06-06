//Copyright 2025 UNN-CS Team
#include <gtest/gtest.h>
#include "circle.h"
#include "tasks.h"

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

TEST(CircleTest, ReciprocalConversion) {
    Circle c(7.5);
    double originalRadius = c.getRadius();
    double originalFerence = c.getFerence();
    double originalArea = c.getArea();

    Circle c2(1);
    c2.setFerence(originalFerence);
    ASSERT_NEAR(c2.getRadius(), originalRadius, 0.001);

    Circle c3(1);
    c3.setArea(originalArea);
    ASSERT_NEAR(c3.getRadius(), originalRadius, 0.001);
}

TEST(CircleTest, MultipleUpdates) {
    Circle c(2);
    c.setRadius(4);
    c.setFerence(25.1327);
    ASSERT_NEAR(c.getRadius(), 4, 0.01);
    ASSERT_NEAR(c.getArea(), 50.265, 0.1);
}

TEST(CircleTest, HighPrecisionRadius) {
    Circle c(123.456);
    ASSERT_NEAR(c.getRadius(), 123.456, 0.0001);
    ASSERT_NEAR(c.getFerence(), 2 * 3.141592653589793 * 123.456, 0.001);
}

TEST(CircleTest, TasksCompilation) {
    double gap = ropeGap();
    double cost = poolConcreteCost();
    double fence = poolFenceCost();
    EXPECT_GT(gap, 0.1);
    EXPECT_GT(cost, 0);
    EXPECT_GT(fence, 0);
}

TEST(CircleTest, ZeroFerence) {
    Circle c(1);
    c.setFerence(0);
    ASSERT_EQ(c.getRadius(), 0);
    ASSERT_EQ(c.getArea(), 0);
}

TEST(CircleTest, SetAreaThenRadius) {
    Circle c(5);
    c.setArea(100);
    double r1 = c.getRadius();
    c.setRadius(r1);
    ASSERT_NEAR(c.getArea(), 100, 0.001);
}
