#pragma once

#include <ostream>
#include "point.h"
#include "pointarray.h"
#include <numeric>
#include <math.h>


class Figure {
private:
    static double triangleArea(const Point& A, const Point&B, const Point& C);

public:
    PointArray points;
    double area_;

    Figure() = default;

    Figure(std::initializer_list<Point> points);

    Figure(PointArray& points);

    Figure(const Figure& f);

    Figure(const Figure* f);

    Figure(Figure&& f);

    virtual ~Figure() = default;

    Point getCenter() const;

    double getArea() const;

    Figure& operator=(const Figure& other);

    Figure& operator=(const Figure* other);

    Figure& operator=(Figure&& other) noexcept;

    bool operator==(Figure& other) const;

    bool operator!=(const Figure& other) const;

    virtual void read(std::istream& is);

    virtual void print(std::ostream& os);

    friend std::ostream& operator<<(std::ostream& os, Figure& figure);

    friend std::istream& operator>>(std::istream& is, Figure& figure);

    operator double() const;

    virtual std::string name() const;

};
