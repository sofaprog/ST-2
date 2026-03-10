// Copyright 2025 UNN-CS
#include "tasks.h"
#include "circle.h"

double calculateRopeGap() {

    const double EARTH_RADIUS = 6378100.0;
    Circle planet(EARTH_RADIUS);
    
    double initialLength = planet.getCircumference();
    double extendedLength = initialLength + 1.0;
    
    planet.changeCircumference(extendedLength);
    

    double newRadius = planet.getRadius();
    double gap = newRadius - EARTH_RADIUS;
    
    return gap;
}

double computePoolExpenses() {

    const double POOL_RADIUS = 3.0;
    const double PATH_WIDTH = 1.0;
    const double CONCRETE_PRICE = 1000.0;
    const double FENCE_PRICE = 2000.0;
    
    Circle pool(POOL_RADIUS);
    Circle outer(POOL_RADIUS + PATH_WIDTH);
    

    double pathArea = outer.getArea() - pool.getArea();
    double concreteExpense = pathArea * CONCRETE_PRICE;
    

    double fenceLength = outer.getCircumference();
    double fenceExpense = fenceLength * FENCE_PRICE;

    double totalExpense = concreteExpense + fenceExpense;
    
    return totalExpense;
}