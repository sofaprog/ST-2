// Copyright 2025 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

class Circle {
 public:
    static constexpr double PI = 3.141592653589793;
    static constexpr double EPS = 1e-10;

    explicit Circle(double r);

    void setRadius(double r);
    void setFerence(double f);
    void setArea(double a);

    double getRadius() const { return radius_; }
    double getFerence() const { return ference_; }
    double getArea() const { return area_; }

 private:
    double radius_;
    double ference_;
    double area_;

    bool isValid(double val) const;
};

#endif  // INCLUDE_CIRCLE_H_
