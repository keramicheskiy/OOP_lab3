#include "rhombus.h"


Rhombus::Rhombus() {
    this->points = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
}

Rhombus::~Rhombus() {}

Rhombus::Rhombus(Point p1, Point p2, Point p3, Point p4) {
    this->points = {p1, p2, p3, p4};
}

void Rhombus::read(std::istream& is) {
    this->points.clear();
    Point point;
    for (int i = 0; i < DEFAULT_POINT_AMOUNT; i++) {
        is >> point;
        this->points.push(point);
    }  
}

std::string Rhombus::name() const {
    return "rhombus";
}
