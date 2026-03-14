// Copyright 2025 UNN-CS
#include <gtest/gtest.h>
#include <cmath>
#include <limits>
#include "circle.h"
#include "tasks.h"

TEST(CircleCreationTest, HandlesNormalRadius) {
    Circle circle(5.0);
    EXPECT_DOUBLE_EQ(circle.getRadius(), 5.0);
    EXPECT_NEAR(circle.getFerence(), 2 * Circle::PI * 5.0, 1e-10);
    EXPECT_NEAR(circle.getArea(), Circle::PI * 25.0, 1e-10);
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
    circle.setRadius(4.0);

    EXPECT_DOUBLE_EQ(circle.getRadius(), 4.0);
    EXPECT_NEAR(circle.getFerence(), 2 * Circle::PI * 4.0, 1e-10);
    EXPECT_NEAR(circle.getArea(), Circle::PI * 16.0, 1e-10);
}

TEST(RadiusModificationTest, RejectsInvalidValues) {
    Circle circle(1.0);
    EXPECT_THROW(circle.setRadius(-5.0), std::invalid_argument);
    EXPECT_THROW(circle.setRadius(0.0), std::invalid_argument);
}

TEST(CircumferenceModificationTest, UpdatesRadiusAndArea) {
    Circle circle(3.0);
    double newCirc = 2 * Circle::PI * 6.0;
    circle.setFerence(newCirc);

    EXPECT_NEAR(circle.getRadius(), 6.0, 1e-10);
    EXPECT_NEAR(circle.getArea(), Circle::PI * 36.0, 1e-10);
}

TEST(CircumferenceModificationTest, HandlesLargeValues) {
    Circle circle(1.0);
    double largeCirc = 2 * Circle::PI * 1000.0;
    circle.setFerence(largeCirc);

    EXPECT_NEAR(circle.getRadius(), 1000.0, 1e-7);
}

TEST(AreaModificationTest, UpdatesRadiusAndCircumference) {
    Circle circle(2.0);
    double newArea = Circle::PI * 25.0;
    circle.setArea(newArea);

    EXPECT_NEAR(circle.getRadius(), 5.0, 1e-10);
    EXPECT_NEAR(circle.getFerence(), 2 * Circle::PI * 5.0, 1e-10);
}

TEST(AreaModificationTest, HandlesVerySmallArea) {
    Circle circle(5.0);
    double tinyArea = Circle::PI * 1e-10;
    circle.setArea(tinyArea);

    EXPECT_NEAR(circle.getRadius(), 1e-5, 1e-6);
}

TEST(MathematicalRelationsTest, CircumferenceFormulaHolds) {
    Circle circle(7.5);
    EXPECT_NEAR(circle.getFerence(),
                2 * Circle::PI * circle.getRadius(), 1e-10);
}

TEST(MathematicalRelationsTest, AreaFormulaHolds) {
    Circle circle(4.2);
    EXPECT_NEAR(circle.getArea(),
                Circle::PI * circle.getRadius() * circle.getRadius(),
                1e-10);
}

TEST(RopeProblemTest, GapCalculationIsCorrect) {
    double gap = calculateRopeGap();
    double expected = 1.0 / (2.0 * Circle::PI);
    EXPECT_NEAR(gap, expected, 1e-6);
}

TEST(RopeProblemTest, GapIsPositive) {
    double gap = calculateRopeGap();
    EXPECT_GT(gap, 0.0);
}

TEST(PoolProblemTest, TotalExpenseIsPositive) {
    double cost = computePoolExpenses();
    EXPECT_GT(cost, 0.0);
}

TEST(PoolProblemTest, ExpenseCalculationIsConsistent) {
    double cost = computePoolExpenses();
    double poolRadius = 3.0;
    double outerRadius = 4.0;
    double pathArea = Circle::PI * (outerRadius * outerRadius -
                                    poolRadius * poolRadius);
    double fenceLength = 2 * Circle::PI * outerRadius;
    double expected = pathArea * 1000.0 + fenceLength * 2000.0;
    EXPECT_NEAR(cost, expected, 1.0);
}
TEST(CircleEdgeCasesTest, HandlesVeryLargeRadius) {
    Circle circle(1e6);
    EXPECT_NEAR(circle.getArea(), Circle::PI * 1e12, 1e-3);
    EXPECT_NEAR(circle.getFerence(), 2 * Circle::PI * 1e6, 1e-3);
}

TEST(PrecisionTest, HandlesHighPrecision) {
    Circle circle(0.1);
    double expectedArea = Circle::PI * 0.01;
    EXPECT_NEAR(circle.getArea(), expectedArea, 1e-12);
}

TEST(ConsistencyTest, SetAndGetMethodsWorkTogether) {
    Circle circle(5.0);
    circle.setRadius(7.0);
    EXPECT_DOUBLE_EQ(circle.getRadius(), 7.0);
    
    double circ = circle.getFerence();
    circle.setFerence(circ);
    EXPECT_NEAR(circle.getRadius(), 7.0, 1e-10);
}

TEST(FractionalValuesTest, HandlesNonIntegerRadius) {
    Circle circle(3.14159);
    EXPECT_NEAR(circle.getRadius(), 3.14159, 1e-10);
    EXPECT_NEAR(circle.getArea(), Circle::PI * 3.14159 * 3.14159, 1e-8);
}

TEST(ValidationTest, RejectsExtremelyLargeValues) {
    Circle circle(1.0);
    EXPECT_THROW(circle.setRadius(1e400), std::invalid_argument);
}

