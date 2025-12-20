#pragma once

#include "point.h"

class PointPair {
public:
    Point first;
    Point second;

    PointPair() = default;

    PointPair(Point& first, Point& second) : first(first), second(second) {}

    bool operator==(const PointPair& other) const {
        return first == other.first && second == other.second;
    }

    bool operator!=(const PointPair& other) const {
        return !(this == &other);
    }
};
