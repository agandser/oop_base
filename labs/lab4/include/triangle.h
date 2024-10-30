#pragma once
#include "figure.h"
#include <vector>
#include <cmath>
#include <iostream>

template <class T>
class Triangle;

template <class T>
std::ostream& operator<<(std::ostream& os, const Triangle<T>& t);

template <class T>
std::istream& operator>>(std::istream& is, Triangle<T>& t);

template <class T>
class Triangle : public Figure<T> {
    friend std::ostream& operator<< <>(std::ostream& os, const Triangle<T>& t);
    friend std::istream& operator>> <>(std::istream& is, Triangle<T>& t);

public:
    Triangle();
    Triangle(const Triangle<T>& t);
    Triangle(Triangle<T>&& t) noexcept;
    Triangle(const std::initializer_list<Point<T>>& t);
    Triangle(Point<T> first, Point<T> second, Point<T> third);
    Triangle(const std::vector<Point<T>>& t);
    ~Triangle() noexcept;

    virtual Point<T> get_center() const override;
    virtual operator double() const override;

    bool operator==(const Triangle<T>& rhs) const noexcept;
    bool operator!=(const Triangle<T>& rhs) const noexcept;
    bool operator>(const Triangle<T>& rhs) const noexcept;
    bool operator<(const Triangle<T>& rhs) const noexcept;
    bool operator>=(const Triangle<T>& rhs) const noexcept;
    bool operator<=(const Triangle<T>& rhs) const noexcept;

    Triangle& operator=(const Triangle<T>& rhs);
    Triangle& operator=(Triangle<T>&& rhs) noexcept;

private:
    static const size_t _num_of_vertices = 3;
    std::vector<Point<T>> _vertices = std::vector<Point<T>>(_num_of_vertices);
};

template <class T>
std::ostream& operator<<(std::ostream& os, const Triangle<T>& t) {
    for (const Point<T>& elem : t._vertices) {
        os << elem << " ";
    }
    return os;
}

template <class T>
std::istream& operator>>(std::istream& is, Triangle<T>& t) {
    for (Point<T>& elem : t._vertices) {
        is >> elem;
    }
    return is;
}

template <class T>
Triangle<T>::Triangle() {
    for (Point<T>& elem : _vertices) {
        elem = std::make_pair(0, 0);
    }
}

template <class T>
Triangle<T>::Triangle(const Triangle<T>& t) {
    _vertices = t._vertices;
}

template <class T>
Triangle<T>::Triangle(Triangle<T>&& t) noexcept {
    _vertices = std::move(t._vertices);
}

template <class T>
Triangle<T>::Triangle(const std::initializer_list<Point<T>>& t) {
    size_t i = 0;
    for (const Point<T>& elem : t) {
        _vertices[i++] = elem;
    }
}

template <class T>
Triangle<T>::Triangle(Point<T> p1, Point<T> p2, Point<T> p3) {
    _vertices[0] = p1;
    _vertices[1] = p2;
    _vertices[2] = p3;
}

template <class T>
Triangle<T>::Triangle(const std::vector<Point<T>>& t) {
    _vertices = t;
}

template <class T>
Triangle<T>::~Triangle() noexcept {}

template <class T>
Point<T> Triangle<T>::get_center() const {
    return std::make_pair(
        (_vertices[0].first + _vertices[1].first + _vertices[2].first) / 3,
        (_vertices[0].second + _vertices[1].second + _vertices[2].second) / 3
    );
}

// Используем формулу Герона для вычисления площади
template <class T>
Triangle<T>::operator double() const {
    double a = std::hypot(_vertices[1].first - _vertices[0].first, _vertices[1].second - _vertices[0].second);
    double b = std::hypot(_vertices[2].first - _vertices[1].first, _vertices[2].second - _vertices[1].second);
    double c = std::hypot(_vertices[2].first - _vertices[0].first, _vertices[2].second - _vertices[0].second);
    
    double s = (a + b + c) / 2;
    
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

template <class T>
bool Triangle<T>::operator==(const Triangle<T>& rhs) const noexcept {
    return std::abs(static_cast<double>(*this) - static_cast<double>(rhs)) < 1e-6;
}

template <class T>
bool Triangle<T>::operator!=(const Triangle<T>& rhs) const noexcept {
    return !(*this == rhs);
}

template <class T>
bool Triangle<T>::operator>(const Triangle<T>& rhs) const noexcept {
    return static_cast<double>(*this) > static_cast<double>(rhs);
}

template <class T>
bool Triangle<T>::operator<(const Triangle<T>& rhs) const noexcept {
    return static_cast<double>(*this) < static_cast<double>(rhs);
}

template <class T>
bool Triangle<T>::operator>=(const Triangle<T>& rhs) const noexcept {
    return !(*this < rhs);
}

template <class T>
bool Triangle<T>::operator<=(const Triangle<T>& rhs) const noexcept {
    return !(*this > rhs);
}

template <class T>
Triangle<T>& Triangle<T>::operator=(const Triangle<T>& rhs) {
    if (this != &rhs) {
        _vertices = rhs._vertices;
    }
    return *this;
}

template <class T>
Triangle<T>& Triangle<T>::operator=(Triangle<T>&& rhs) noexcept {
    if (this != &rhs) {
        _vertices = std::move(rhs._vertices);
    }
    return *this;
}
