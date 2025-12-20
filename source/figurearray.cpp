#include "figurearray.h"
#include <string>
#include <initializer_list>
#include <math.h>
#include <fmt/core.h>

FigureArray::FigureArray(const std::initializer_list<Figure*> &list) : size(list.size()), capacity(size), data(new Figure*[size]) {
    int i = 0;
    for (const auto& element : list)
        data[i++] = element;
}

FigureArray::FigureArray(const FigureArray& other)
    : size(other.size), capacity(other.capacity), data(new Figure*[other.capacity])
{
    for (size_t i = 0; i < size; i++)
        data[i] = other.data[i];
}

FigureArray::FigureArray(FigureArray&& other) noexcept : size(other.size), capacity(other.capacity), data(other.data) {
    other.size = 0;
    other.capacity = 0;
    other.data = nullptr;
}

FigureArray::~FigureArray() {
    for (size_t i = 0; i < size; i++)
        delete data[i];
    delete[] data;
}

size_t FigureArray::getSize() const {
    return size;
}

size_t FigureArray::getCapacity() const {
    return capacity;
}

Figure* FigureArray::operator[](size_t index) {
    if (index >= size)
        throw std::out_of_range(fmt::format("Index out of range: {}", index));
    return data[index];
}

void FigureArray::push(Figure* f) {
    if (size == capacity) {
        size_t newCap = capacity ? capacity * 2 : 1;
        Figure** newData = new Figure*[newCap];
        for (size_t i = 0; i < size; ++i)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity = newCap;
    }
    data[size++] = f;
}

void FigureArray::set(size_t index, Figure* f) {
    if (index >= size) throw std::out_of_range("Index out of range");
    data[index] = f;
}


void FigureArray::remove(size_t index) {
    if (index >= size) return;
    delete data[index];
    for (size_t i = index; i + 1 < size; ++i)
        data[i] = data[i + 1];
    size--;
}


void FigureArray::resize(size_t newSize) {
    Figure** newData = new Figure*[newSize];
    size_t minSize = std::min(size, newSize);
    for (size_t i = 0; i < minSize; ++i)
        newData[i] = data[i];
    delete[] data;
    data = newData;
    size = minSize;
    capacity = newSize;
}

FigureArray& FigureArray::operator=(const FigureArray& other) {
    if (this == &other) return *this;
    delete[] data;
    size = other.size;
    capacity = other.capacity;
    data = new Figure*[capacity];
    for (size_t i = 0; i < size; i++)
        data[i] = other.data[i];
    return *this;
}

FigureArray& FigureArray::operator=(FigureArray&& other) noexcept {
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

bool FigureArray::operator==(const FigureArray& other) const {
    if (size != other.size) return false;

    for (size_t i = 0; i < size; i++) {
        if (data[i] != other.data[i]) return false;
    }
    return true;
}

Figure** FigureArray::begin() {
    return data;
}

Figure** FigureArray::end() {
    return data + size;
}

