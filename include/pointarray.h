#pragma once

#include <initializer_list>
#include <cstddef>

class Point;

class PointArray {
private:
    size_t size = 0, capacity = 0;
    Point* data = nullptr;

public:
    PointArray() = default;

    PointArray(const size_t & size, const Point& value);

    PointArray(const std::initializer_list<Point> &list);

    PointArray(const PointArray& other);

    PointArray(PointArray&& other) noexcept;

    ~PointArray();

    size_t getSize() const;

    size_t getCapacity() const;

    Point& operator[](size_t index);

    const Point& operator[](size_t index) const;

    void push(const Point& element);

    Point pop();

    void remove(size_t index);

    void clear();

    void set(size_t index, const Point& element);

    void resize(size_t size);

    bool contains(const Point& element) const;

    PointArray& operator=(const PointArray& other);

    PointArray& operator=(PointArray&& other) noexcept;

    bool operator==(const PointArray& other) const;

    Point* begin();

    Point* end();

    const Point* begin() const;

    const Point* end() const;

    static bool hasThreeCollinearPoints(PointArray& points);
    

};
