#include <ostream>
#include "point.h"
#include "pointpair.h"
#include "pointarray.h"
#include "pointpairarray.h"
#include <numeric>
#include <limits>
#include <math.h>
#include "figure.h"

double Figure::triangleArea(const Point& A, const Point&B, const Point& C) {
    double a = Point::distance(B, C);
    double b = Point::distance(A, C);
    double c = Point::distance(B, A);
    double p = (a + b + c) / 2;
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

Figure::Figure(std::initializer_list<Point> points) {
    if (points.size() < 3) throw std::runtime_error("Any figure must have at least 3 points!");

    for (Point p : points)
        this->points.push(p);
    
    if (PointArray::hasThreeCollinearPoints(this->points)) throw std::runtime_error("Three or more points are collinear!");
}

Figure::Figure(PointArray& points) : points(points) {
    if (points.getSize() < 3) throw std::runtime_error("Any figure must have at least 3 points!");

    if (PointArray::hasThreeCollinearPoints(points)) throw std::runtime_error("Three or more points are collinear!");
}

Figure::Figure(const Figure& f) : points(f.points) {}

Figure::Figure(const Figure* f) : points(f->points) {}

Figure::Figure(Figure&& f) : points(std::move(f.points)) {}

Point Figure::getCenter() const {
    double sumX = 0, sumY = 0;
    for (int i = 0; i < points.getSize(); ++i) {
        sumX += points[i].x;
        sumY += points[i].y;
    }
    return Point(sumX / points.getSize(), sumY / points.getSize());
}

double Figure::getArea() const {
    if (points.getSize() < 3) return 0.0;
    Point O = getCenter();
    PointPairArray triangles;
    for (Point A : points) {
        for (Point B : points) {
            for (Point C : points) {
                if ((C - O).isInsideTheSector(A - O, B - O)) break;
                if (!triangles.contains({A, B}) && !triangles.contains({B, A})) triangles.push(PointPair {A, B});
            }
        }
    }
    double area_ = 0;
    for (PointPair triangle : triangles) {
        area_ += abs(triangleArea(O, triangle.first, triangle.second));
    }
    return area_ * 2;
}

Figure& Figure::operator=(const Figure* other) {
    if (this == other) return *this;

    points = other->points;

    return *this;
}

Figure& Figure::operator=(const Figure& other) {
    if (this == &other) return *this;

    points = other.points;

    return *this;
}

Figure& Figure::operator=(Figure&& other) noexcept {
    if (this == &other) return *this;

    points = std::move(other.points);

    return *this;
}

bool Figure::operator==(Figure& other) const {
    if (points.getSize() != other.points.getSize()) return false;
    for (int i = 0; i < points.getSize(); i++) {
        if (!other.points.contains(points[i])) return false;
    }
    return true;
}

bool Figure::operator!=(const Figure& other) const {
    return !(*this == other);
}

void Figure::read(std::istream& is) {
    this->points.clear();
    Point point;

    while (is >> point) {
        this->points.push(point);
    }

    is.clear();
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Figure::print(std::ostream& os) {
    for (int i = 0; i < points.getSize(); i++) {
        os << this->points[i] << ((i != points.getSize() - 1)? ", " : "");
    }
}

std::istream& operator>>(std::istream& is, Figure& figure) {
    figure.read(is);
    return is;
}

std::ostream& operator<<(std::ostream& os, Figure& figure) {
    figure.print(os);
    return os;
}


Figure::operator double() const {
    return getArea();
}

std::string Figure::name() const {
    return "figure";
}

