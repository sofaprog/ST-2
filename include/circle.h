// Copyright 2025 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

class Circle {
 public:
    static constexpr double PI_VALUE = 3.141592653589793;
    static constexpr double TOLERANCE = 1e-10;
    Circle(double r);
    void changeRadius(double r);
    void changeCircumference(double c);
    void changeArea(double a);
    
    double getRadius() const { return radius_; }
    double getCircumference() const { return circumference_; }
    double getArea() const { return area_; }
    
 private:
    double radius_;
    double circumference_;
    double area_;
    bool isValidValue(double val) const;
};

#endif  // INCLUDE_CIRCLE_H_