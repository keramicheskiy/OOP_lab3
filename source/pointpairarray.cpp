#include "pointpairarray.h"
#include <cstddef>
#include <string>
#include <initializer_list>
#include <math.h>
#include <fmt/core.h>

PointPairArray::PointPairArray(const size_t & size, const PointPair& value) : size(size), capacity(size), data(new PointPair[size]) {
    for (int i = 0; i < size; i++)
        data[i] = value;
}

PointPairArray::PointPairArray(const std::initializer_list<PointPair> &list) : size(list.size()), capacity(size), data(new PointPair[size]) {
    int i = 0;
    for (const auto& element : list)
        data[i++] = element;
}

PointPairArray::PointPairArray(const PointPairArray& other) : size(other.size), capacity(other.capacity), data(new PointPair[size]) {
    for (size_t i = 0; i < size; i++)
        data[i] = other.data[i];
}

PointPairArray::PointPairArray(PointPairArray&& other) noexcept : size(other.size), capacity(other.capacity), data(other.data) {
    other.size = 0;
    other.capacity = 0;
    other.data = nullptr;
}

PointPairArray::~PointPairArray() { delete[] data; }

size_t PointPairArray::getSize() const {
    return size;
}

size_t PointPairArray::getCapacity() const {
    return capacity;
}

PointPair& PointPairArray::operator[](size_t index) {
    if (index >= size)
        throw std::out_of_range(fmt::format("Index out of range: {}", index));
    return data[index];
}

const PointPair& PointPairArray::operator[](size_t index) const {
    if (index >= size)
        throw std::out_of_range(fmt::format("Index out of range: {}", index));
    return data[index];
}

void PointPairArray::push(const PointPair& element) {
    if (size == capacity) {
        size_t newCap = capacity ? capacity * 2 : 1;
        PointPair* newData = new PointPair[newCap];
        for (int i = 0; i < size; i++)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity = newCap;
    }
    data[size++] = element;
}

PointPair PointPairArray::pop() {
    if (size == 0) throw std::out_of_range("Pop is forbidden for empty arrays.");

    return data[--size];
}

void PointPairArray::remove(size_t index) {
    if (index >= size) return;
    for (size_t i = index; i + 1 < size; ++i)
        data[i] = data[i + 1];
    size--;
}

void PointPairArray::clear() {
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
}

void PointPairArray::set(size_t index, const PointPair& element) {
    if (index >= size)
        throw std::out_of_range(fmt::format("Index out of range: {}", index));
    data[index] = element;
}

void PointPairArray::resize(size_t newSize) {
    PointPair* newData = new PointPair[newSize];
    for (int i = 0; i < std::min(size, newSize); i++)
        newData[i] = data[i];
    delete[] data;
    data = newData;
    size = std::min(newSize, size);
    capacity = newSize;
}

bool PointPairArray::contains(const PointPair& element) const {
    for (int i = 0; i < size; i++) {
        if (data[i] == element) return true;
    }
    return false;
}

PointPairArray& PointPairArray::operator=(const PointPairArray& other) {
    if (this == &other) return *this;

    PointPair* newData = new PointPair[other.capacity];
    for (size_t i = 0; i < other.size; i++)
        newData[i] = other.data[i];
    delete[] data;
    data = newData;
    size = other.size;
    capacity = other.capacity;

    return *this;
}

PointPairArray& PointPairArray::operator=(PointPairArray&& other) noexcept {
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

bool PointPairArray::operator==(const PointPairArray& other) const {
    if (size != other.size) return false;

    for (size_t i = 0; i < size; i++) {
        if (data[i] != other.data[i]) return false;
    }
    return true;
}

PointPair* PointPairArray::begin() {
    return data;
}

PointPair* PointPairArray::end() {
    return data + size;
}

const PointPair* PointPairArray::begin() const {
    return data;
}

const PointPair* PointPairArray::end() const {
    return data + size;
}

