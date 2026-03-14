// Copyright 2025 UNN-CS
#include <cmath>
#include <stdexcept>
#include "circle.h"

Circle::Circle(double r) {
    changeRadius(r);
}

bool Circle::isValidValue(double val) const {
    if (std::isnan(val) || std::isinf(val)) return false;
    if (val <= TOLERANCE) return false;
    if (val > 1e300) return false;
    return true;
}

void Circle::changeRadius(double r) {
    if (!isValidValue(r)) {
        throw std::invalid_argument("Invalid radius value");
    }
    radius_ = r;
    circumference_ = 2.0 * PI_VALUE * radius_;
    area_ = PI_VALUE * radius_ * radius_;
}

void Circle::changeCircumference(double c) {
    if (!isValidValue(c)) {
        throw std::invalid_argument("Invalid circumference value");
    }
    circumference_ = c;
    radius_ = circumference_ / (2.0 * PI_VALUE);
    area_ = PI_VALUE * radius_ * radius_;
}

void Circle::changeArea(double a) {
    if (!isValidValue(a)) {
        throw std::invalid_argument("Invalid area value");
    }
    area_ = a;
    radius_ = std::sqrt(area_ / PI_VALUE);
    circumference_ = 2.0 * PI_VALUE * radius_;
}
