#pragma once

#include "figure.h"


class Rhombus : public Figure {
private:
    const size_t DEFAULT_POINT_AMOUNT = 4;

public:
    Rhombus();

    ~Rhombus();

    Rhombus(Point p1, Point p2, Point p3, Point p4);

    void read(std::istream& is) override;

    std::string name() const override;

};
