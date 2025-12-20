#pragma once

#include <initializer_list>
#include "pointpair.h"

class PointPairArray {
private:
    size_t size = 0, capacity = 0;
    PointPair* data = nullptr;

public:
    PointPairArray() = default;

    PointPairArray(const size_t & size, const PointPair& value);

    PointPairArray(const std::initializer_list<PointPair> &list);

    PointPairArray(const PointPairArray& other);

    PointPairArray(PointPairArray&& other) noexcept;

    ~PointPairArray();

    size_t getSize() const;

    size_t getCapacity() const;

    PointPair& operator[](size_t index);

    const PointPair& operator[](size_t index) const;

    void push(const PointPair& element);

    PointPair pop();

    void remove(size_t index);

    void clear();

    void set(size_t index, const PointPair& element);

    void resize(size_t size);

    bool contains(const PointPair& element) const;

    PointPairArray& operator=(const PointPairArray& other);

    PointPairArray& operator=(PointPairArray&& other) noexcept;

    bool operator==(const PointPairArray& other) const;

    PointPair* begin();

    PointPair* end();

    const PointPair* begin() const;

    const PointPair* end() const;
    

};
