#include "pointarray.h"
#include "point.h"
#include <cstddef>
#include <string>
#include <initializer_list>
#include <math.h>
#include <fmt/core.h>

PointArray::PointArray(const size_t & size, const Point& value) : size(size), capacity(size), data(new Point[size]) {
    for (int i = 0; i < size; i++)
        data[i] = value;
}

PointArray::PointArray(const std::initializer_list<Point> &list) : size(list.size()), capacity(size), data(new Point[size]) {
    int i = 0;
    for (const auto& element : list)
        data[i++] = element;
}

PointArray::PointArray(const PointArray& other) : size(other.size), capacity(other.capacity), data(new Point[size]) {
    for (size_t i = 0; i < size; i++)
        data[i] = other.data[i];
}

PointArray::PointArray(PointArray&& other) noexcept : size(other.size), capacity(other.capacity), data(other.data) {
    other.size = 0;
    other.capacity = 0;
    other.data = nullptr;
}

PointArray::~PointArray() {
    delete[] data;
}

size_t PointArray::getSize() const {
    return size;
}

size_t PointArray::getCapacity() const {
    return capacity;
}

Point& PointArray::operator[](size_t index) {
    if (index >= size)
        throw std::out_of_range(fmt::format("Index out of range: {}", index));
    return data[index];
}

const Point& PointArray::operator[](size_t index) const {
    if (index >= size)
        throw std::out_of_range(fmt::format("Index out of range: {}", index));
    return data[index];
}

void PointArray::push(const Point& element) {
    if (size == capacity) {
        size_t newCap = capacity ? capacity * 2 : 1;
        Point* newData = new Point[newCap];
        for (int i = 0; i < size; i++)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity = newCap;
    }
    data[size++] = element;
}

Point PointArray::pop() {
    if (size == 0) throw std::out_of_range("Pop is forbidden for empty arrays.");

    return data[--size];
}

void PointArray::remove(size_t index) {
    if (index >= size) return;
    for (size_t i = index; i + 1 < size; ++i)
        data[i] = data[i + 1];
    size--;
}

void PointArray::clear() {
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
}

void PointArray::set(size_t index, const Point& element) {
    if (index >= size)
        throw std::out_of_range(fmt::format("Index out of range: {}", index));
    data[index] = element;
}

void PointArray::resize(size_t newSize) {
    Point* newData = new Point[newSize];
    for (int i = 0; i < std::min(size, newSize); i++)
        newData[i] = data[i];
    delete[] data;
    data = newData;
    size = std::min(newSize, size);
    capacity = newSize;
}

bool PointArray::contains(const Point& element) const {
    for (int i = 0; i < size; i++) {
        if (data[i] == element) return true;
    }
    return false;
}

PointArray& PointArray::operator=(const PointArray& other) {
    if (this == &other) return *this;

    Point* newData = new Point[other.capacity];
    for (size_t i = 0; i < other.size; i++)
        newData[i] = other.data[i];
    delete[] data;
    data = newData;
    size = other.size;
    capacity = other.capacity;

    return *this;
}

PointArray& PointArray::operator=(PointArray&& other) noexcept {
    if (this == &other) return *this;

    delete[] data;
    data = other.data;
    size = other.size;
    capacity = other.capacity;
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;

    return *this;
}

bool PointArray::operator==(const PointArray& other) const {
    if (size != other.size) return false;

    for (size_t i = 0; i < size; i++) {
        if (data[i] != other.data[i]) return false;
    }
    return true;
}

Point* PointArray::begin() {
    return data;
}

Point* PointArray::end() {
    return data + size;
}

const Point* PointArray::begin() const {
    return data;
}

const Point* PointArray::end() const {
    return data + size;
}

bool PointArray::hasThreeCollinearPoints(PointArray& points) {
    for (int i = 0; i < points.getSize(); i++)
        for (int j = 0; j < points.getSize(); j++)
            for (int k = 0; k < points.getSize(); k++)
                if (i != j && i != k && j != k && Point::areCollinear(points[i], points[j], points[k]))
                    return true;
    return false;
}