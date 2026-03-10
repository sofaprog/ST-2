// Copyright 2025 UNN-CS
#include <gtest/gtest.h>
#include <cmath>
#include <limits>
#include "circle.h"
#include "tasks.h"

using namespace std;


TEST(CircleCreationTest, HandlesNormalRadius) {
    Circle circle(5.0);
    EXPECT_DOUBLE_EQ(circle.getRadius(), 5.0);
    EXPECT_NEAR(circle.getCircumference(), 2 * Circle::PI_VALUE * 5.0, 1e-10);
    EXPECT_NEAR(circle.getArea(), Circle::PI_VALUE * 25.0, 1e-10);
}

TEST(CircleCreationTest, HandlesVerySmallRadius) {
    Circle circle(1e-9);
    EXPECT_NEAR(circle.getRadius(), 1e-9, 1e-10);
}

TEST(CircleCreationTest, RejectsZeroRadius) {
    EXPECT_THROW(Circle(0.0), std::invalid_argument);
}

TEST(CircleCreationTest, RejectsNegativeRadius) {
    EXPECT_THROW(Circle(-3.0), std::invalid_argument);
}

TEST(CircleCreationTest, RejectsNaNRadius) {
    EXPECT_THROW(Circle(std::numeric_limits<double>::quiet_NaN()), 
                 std::invalid_argument);
}


TEST(RadiusModificationTest, UpdatesCircumferenceAndArea) {
    Circle circle(2.0);
    circle.changeRadius(4.0);
    
    EXPECT_DOUBLE_EQ(circle.getRadius(), 4.0);
    EXPECT_NEAR(circle.getCircumference(), 2 * Circle::PI_VALUE * 4.0, 1e-10);
    EXPECT_NEAR(circle.getArea(), Circle::PI_VALUE * 16.0, 1e-10);
}

TEST(RadiusModificationTest, RejectsInvalidValues) {
    Circle circle(1.0);
    EXPECT_THROW(circle.changeRadius(-5.0), std::invalid_argument);
    EXPECT_THROW(circle.changeRadius(0.0), std::invalid_argument);
}


TEST(CircumferenceModificationTest, UpdatesRadiusAndArea) {
    Circle circle(3.0);
    double newCirc = 2 * Circle::PI_VALUE * 6.0;
    circle.changeCircumference(newCirc);
    
    EXPECT_NEAR(circle.getRadius(), 6.0, 1e-10);
    EXPECT_NEAR(circle.getArea(), Circle::PI_VALUE * 36.0, 1e-10);
}

TEST(CircumferenceModificationTest, HandlesLargeValues) {
    Circle circle(1.0);
    double largeCirc = 2 * Circle::PI_VALUE * 1000.0;
    circle.changeCircumference(largeCirc);
    
    EXPECT_NEAR(circle.getRadius(), 1000.0, 1e-7);
}


TEST(AreaModificationTest, UpdatesRadiusAndCircumference) {
    Circle circle(2.0);
    double newArea = Circle::PI_VALUE * 25.0;
    circle.changeArea(newArea);
    
    EXPECT_NEAR(circle.getRadius(), 5.0, 1e-10);
    EXPECT_NEAR(circle.getCircumference(), 2 * Circle::PI_VALUE * 5.0, 1e-10);
}

TEST(AreaModificationTest, HandlesVerySmallArea) {
    Circle circle(5.0);
    double tinyArea = Circle::PI_VALUE * 1e-10;
    circle.changeArea(tinyArea);
    
    EXPECT_NEAR(circle.getRadius(), 1e-5, 1e-6);
}


TEST(MathematicalRelationsTest, CircumferenceFormulaHolds) {
    Circle circle(7.5);
    EXPECT_NEAR(circle.getCircumference(), 
                2 * Circle::PI_VALUE * circle.getRadius(), 1e-10);
}

TEST(MathematicalRelationsTest, AreaFormulaHolds) {
    Circle circle(4.2);
    EXPECT_NEAR(circle.getArea(), 
                Circle::PI_VALUE * circle.getRadius() * circle.getRadius(), 
                1e-10);
}


TEST(RopeProblemTest, GapCalculationIsCorrect) {
    double gap = calculateRopeGap();
    double expected = 1.0 / (2.0 * Circle::PI_VALUE);
    EXPECT_NEAR(gap, expected, 1e-6);
}

TEST(RopeProblemTest, GapIsPositive) {
    double gap = calculateRopeGap();
    EXPECT_GT(gap, 0.0);
}

TEST(RopeProblemTest, GapIsReasonable) {
    double gap = calculateRopeGap();
    EXPECT_LT(gap, 1.0);
    EXPECT_GT(gap, 0.1);
}


TEST(PoolProblemTest, TotalExpenseIsPositive) {
    double cost = computePoolExpenses();
    EXPECT_GT(cost, 0.0);
}

TEST(PoolProblemTest, ExpenseCalculationIsConsistent) {
    double cost = computePoolExpenses();
    

    double poolRadius = 3.0;
    double outerRadius = 4.0;
    double pathArea = Circle::PI_VALUE * (outerRadius * outerRadius - 
                                          poolRadius * poolRadius);
    double fenceLength = 2 * Circle::PI_VALUE * outerRadius;
    double expected = pathArea * 1000.0 + fenceLength * 2000.0;
    
    EXPECT_NEAR(cost, expected, 1.0);
}

TEST(PoolProblemTest, ConcreteExpenseDominates) {

    Circle pool(3.0);
    Circle outer(4.0);
    double pathArea = outer.getArea() - pool.getArea();
    double concrete = pathArea * 1000.0;
    double fence = outer.getCircumference() * 2000.0;
    
    EXPECT_GT(concrete, fence);
}


TEST(PrecisionTest, WorksWithVeryLargeNumbers) {
    Circle circle(1e6);
    EXPECT_NEAR(circle.getArea(), Circle::PI_VALUE * 1e12, 1.0);
}

TEST(PrecisionTest, WorksWithVerySmallNumbers) {
    Circle circle(1e-6);
    EXPECT_NEAR(circle.getArea(), Circle::PI_VALUE * 1e-12, 1e-20);
}