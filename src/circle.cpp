// Copyright 2025 UNN-CS
#include <cmath>
#include <stdexcept>
#include "circle.h"

Circle::Circle(double r) {
    setRadius(r);
}

bool Circle::isValid(double val) const {
    if (std::isnan(val) || std::isinf(val)) return false;
    if (val <= EPS) return false;
    if (val > 1e300) return false;
    return true;
}

void Circle::setRadius(double r) {
    if (!isValid(r)) {
        throw std::invalid_argument("Invalid radius value");
    }
    radius_ = r;
    ference_ = 2.0 * PI * radius_;
    area_ = PI * radius_ * radius_;
}

void Circle::setFerence(double c) {
    if (!isValid(c)) {
        throw std::invalid_argument("Invalid circumference value");
    }
    ference_ = c;
    radius_ = ference_ / (2.0 * PI);
    area_ = PI * radius_ * radius_;
}

void Circle::setArea(double a) {
    if (!isValid(a)) {
        throw std::invalid_argument("Invalid area value");
    }
    area_ = a;
    radius_ = std::sqrt(area_ / PI);
    ference_ = 2.0 * PI * radius_;
}
