#include <math.h>
#include <iostream>
#include <fmt/core.h>
#include "point.h"

Point::Point(double x, double y) : x(x), y(y) {}

double Point::distance(const Point& a, const Point& b) {
    return std::hypot(a.x - b.x, a.y - b.y);
}

double Point::radialDistance() {
    return std::hypot(this->x, this->y);
}

Point Point::operator+(Point& other) {
    return Point(this->x + other.x, this->y + other.y);
}

Point Point::operator-(Point& other) {
    return Point(this->x - other.x, this->y - other.y);
}

double Point::angle() const {
    double degrees = atan2(this->y, this->x) / M_PI * 180;
    if (degrees < 0) degrees += 360;
    return degrees;
}

bool Point::isInsideTheSector(const Point& a, const Point& b) {
    double minAngle = std::min(a.angle(), b.angle());
    double maxAngle = std::max(a.angle(), b.angle());
    double angleC = this->angle();
    if (maxAngle - minAngle > 180) minAngle += 360;
    
    return std::min(minAngle, maxAngle) <= angleC && angleC <= std::max(minAngle, maxAngle) 
        || std::min(minAngle, maxAngle) <= angleC + 360 && angleC + 360 <= std::max(minAngle, maxAngle);
} 

bool Point::areCollinear(Point& a, Point& b, Point& c) {
    double allowedError = 1e-9;
    double area = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    return std::abs(area) < allowedError;
}

bool Point::operator==(const Point& other) const {
    return this->x == other.x && y == other.y;
}

bool Point::operator!=(const Point& other) const {
    return this->x != other.x || this->y != other.y;
}

std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}

std::ostream& operator<<(std::ostream& os, Point& p) {
    os << fmt::format("({}, {})", p.x, p.y);
    return os;
}

