#pragma once
#include "figure.h"
#include <vector>
#include <cmath>
#include <iostream>

template <class T>
class Octagon;

template <class T>
std::ostream& operator<<(std::ostream& os, const Octagon<T>& o);

template <class T>
std::istream& operator>>(std::istream& is, Octagon<T>& o);

template <class T>
class Octagon : public Figure<T> {
    friend std::ostream& operator<< <>(std::ostream& os, const Octagon<T>& o);
    friend std::istream& operator>> <>(std::istream& is, Octagon<T>& o);

public:
    Octagon();
    Octagon(const Octagon<T>& o);
    Octagon(Octagon<T>&& o) noexcept;
    Octagon(const std::initializer_list<Point<T>>& t);
    Octagon(Point<T> first, Point<T> second, Point<T> third, Point<T> fourth,
            Point<T> fifth, Point<T> sixth, Point<T> seventh, Point<T> eighth);
    Octagon(const std::vector<Point<T>>& t);
    ~Octagon() noexcept;

    virtual Point<T> get_center() const override;
    virtual operator double() const override;

    bool operator==(const Octagon<T>& rhs) const noexcept;
    bool operator!=(const Octagon<T>& rhs) const noexcept;
    bool operator>(const Octagon<T>& rhs) const noexcept;
    bool operator<(const Octagon<T>& rhs) const noexcept;
    bool operator>=(const Octagon<T>& rhs) const noexcept;
    bool operator<=(const Octagon<T>& rhs) const noexcept;

    Octagon& operator=(const Octagon<T>& rhs);
    Octagon& operator=(Octagon<T>&& rhs) noexcept;

private:
    static const size_t _num_of_vertices = 8;
    std::vector<Point<T>> _vertices = std::vector<Point<T>>(_num_of_vertices);
};

template <class T>
Octagon<T>::Octagon() {
    for (Point<T>& elem : _vertices) {
        elem = std::make_pair(0, 0);
    }
}

template <class T>
Octagon<T>::Octagon(const Octagon<T>& o) {
    _vertices = o._vertices;
}

template <class T>
Octagon<T>::Octagon(Octagon<T>&& o) noexcept {
    _vertices = std::move(o._vertices);
}

template <class T>
Octagon<T>::Octagon(const std::initializer_list<Point<T>>& t) {
    size_t i = 0;
    for (const Point<T>& elem : t) {
        _vertices[i] = elem;
        ++i;
    }
}

template <class T>
Octagon<T>::Octagon(Point<T> p1, Point<T> p2, Point<T> p3, Point<T> p4, Point<T> p5, Point<T> p6, Point<T> p7, Point<T> p8) {
    _vertices[0] = p1;
    _vertices[1] = p2;
    _vertices[2] = p3;
    _vertices[3] = p4;
    _vertices[4] = p5;
    _vertices[5] = p6;
    _vertices[6] = p7;
    _vertices[7] = p8;
}

template <class T>
Octagon<T>::Octagon(const std::vector<Point<T>>& t) {
    _vertices = t;
}

template <class T>
Octagon<T>::~Octagon() noexcept {}

template <class T>
Point<T> Octagon<T>::get_center() const {
    T x_sum = 0;
    T y_sum = 0;
    for (const auto& vertex : _vertices) {
        x_sum += vertex.first;
        y_sum += vertex.second;
    }
    return { x_sum / _num_of_vertices, y_sum / _num_of_vertices };
}

template <class T>
Octagon<T>::operator double() const {
    double area = 0.0;
    for (size_t i = 0; i < _num_of_vertices; ++i) {
        size_t j = (i + 1) % _num_of_vertices;
        area += (_vertices[i].first * _vertices[j].second) - (_vertices[j].first * _vertices[i].second);
    }
    return std::abs(area) / 2.0;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Octagon<T>& o) {
    for (const Point<T>& elem : o._vertices) {
        os << elem << " ";
    }
    return os;
}

template <class T>
std::istream& operator>>(std::istream& is, Octagon<T>& o) {
    for (Point<T>& elem : o._vertices) {
        is >> elem;
    }
    return is;
}

template <class T>
bool Octagon<T>::operator==(const Octagon<T>& rhs) const noexcept {
    return is_eq(static_cast<double>(*this), static_cast<double>(rhs));
}

template <class T>
bool Octagon<T>::operator!=(const Octagon<T>& rhs) const noexcept {
    return !(*this == rhs);
}

template <class T>
bool Octagon<T>::operator>(const Octagon<T>& rhs) const noexcept {
    return static_cast<double>(*this) > static_cast<double>(rhs);
}

template <class T>
bool Octagon<T>::operator>=(const Octagon<T>& rhs) const noexcept {
    return (*this > rhs) || (*this == rhs);
}

template <class T>
bool Octagon<T>::operator<(const Octagon<T>& rhs) const noexcept {
    return !(*this >= rhs);
}

template <class T>
bool Octagon<T>::operator<=(const Octagon<T>& rhs) const noexcept {
    return !(*this > rhs);
}

template <class T>
Octagon<T>& Octagon<T>::operator=(const Octagon<T>& rhs) {
    if (this != &rhs) {
        _vertices = rhs._vertices;
    }
    return *this;
}

template <class T>
Octagon<T>& Octagon<T>::operator=(Octagon<T>&& rhs) noexcept {
    if (this != &rhs) {
        _vertices = std::move(rhs._vertices);
    }
    return *this;
}
