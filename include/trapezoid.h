#pragma once

#include "figure.h"


class Trapezoid : public Figure {
private:
    const size_t DEFAULT_POINT_AMOUNT = 4;

public:
    Trapezoid();

    ~Trapezoid();

    Trapezoid(Point p1, Point p2, Point p3, Point p4);

    void read(std::istream& is) override;

    std::string name() const override;

};
