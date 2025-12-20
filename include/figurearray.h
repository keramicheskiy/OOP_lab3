#pragma once
#include <initializer_list>
#include "figure.h"

class FigureArray {
private:
    size_t size = 0;
    size_t capacity = 0;
    Figure** data = nullptr;

public:
    FigureArray() = default;

    FigureArray(const size_t size);
    
    FigureArray(const std::initializer_list<Figure*> &list);

    FigureArray(const FigureArray& other);

    FigureArray(FigureArray&& other) noexcept;

    ~FigureArray();

    size_t getSize() const;

    size_t getCapacity() const;

    Figure* operator[](size_t index);

    const Figure* operator[](size_t index) const;

    void push(Figure* f);

    void set(size_t index, Figure* f);

    void remove(size_t index);

    void resize(size_t newSize);

    FigureArray& operator=(const FigureArray& other);

    FigureArray& operator=(FigureArray&& other) noexcept;

    bool operator==(const FigureArray& other) const;

    Figure** begin();

    Figure** end();
};