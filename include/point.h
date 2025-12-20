#pragma once

#include <math.h>
#include <iostream>
#include <fmt/core.h>

class Point {
public:
    double x, y;

    Point(double x = 0, double y = 0);

    static double distance(const Point& a, const Point& b);

    double radialDistance();

    Point operator+(Point& other);

    Point operator-(Point& other);

    double angle() const;

    bool isInsideTheSector(const Point& a, const Point& b);

    static bool areCollinear(Point& a, Point& b, Point& c);

    bool operator==(const Point& other) const;

    bool operator!=(const Point& other) const;

    friend std::istream& operator>>(std::istream& is, Point& p);

    friend std::ostream& operator<<(std::ostream& os, Point& p);

};

template<>
struct fmt::formatter<Point> {
    constexpr auto parse(fmt::format_parse_context& ctx) { return ctx.begin(); }

    template <typename FormatContext>
    auto format(const Point& p, FormatContext& ctx) {
        return fmt::format_to(ctx.out(), "({}, {})", p.x, p.y);
    }
};