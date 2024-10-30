#pragma once
#include "figure.h"
#include <vector>
#include <cmath>
#include <iostream>

template <class T>
class Hexagon;

template <class T>
std::ostream& operator<<(std::ostream& os, const Hexagon<T>& h);

template <class T>
std::istream& operator>>(std::istream& is, Hexagon<T>& h);

template <class T>
class Hexagon : public Figure<T> {
    friend std::ostream& operator<< <>(std::ostream& os, const Hexagon<T>& h);
    friend std::istream& operator>> <>(std::istream& is, Hexagon<T>& h);

public:
    Hexagon();
    Hexagon(const std::vector<Point<T>>& t);
    Hexagon(const std::initializer_list<Point<T>>& t);
    Hexagon(Point<T> first, Point<T> second, Point<T> third, Point<T> fourth, Point<T> fifth, Point<T> sixth);
    Hexagon(const Hexagon<T>& h);
    Hexagon(Hexagon<T>&& h) noexcept;
    ~Hexagon() noexcept;

    virtual Point<T> get_center() const noexcept override;
    virtual operator double() const noexcept override;
    
    bool operator==(const Hexagon<T>& rhs) const noexcept;
    bool operator!=(const Hexagon<T>& rhs) const noexcept;
    bool operator>(const Hexagon<T>& rhs) const noexcept;
    bool operator<(const Hexagon<T>& rhs) const noexcept;
    bool operator>=(const Hexagon<T>& rhs) const noexcept;
    bool operator<=(const Hexagon<T>& rhs) const noexcept;
    
    Hexagon<T>& operator=(const Hexagon<T>& rhs);
    Hexagon<T>& operator=(Hexagon<T>&& rhs) noexcept;

private:
    static const size_t _num_of_vertices = 6;
    std::vector<Point<T>> _vertices = std::vector<Point<T>>(_num_of_vertices);
};

template <class T>
std::ostream& operator<<(std::ostream& os, const Hexagon<T>& h) {
    for (const Point<T>& elem : h._vertices) {
        os << elem << " ";
    }
    return os;
}

template <class T>
std::istream& operator>>(std::istream& is, Hexagon<T>& h) {
    for (Point<T>& elem : h._vertices) {
        is >> elem;
    }
    return is;
}

template <class T>
Hexagon<T>::Hexagon() {
    for (Point<T>& elem : _vertices) {
        elem = std::make_pair(0, 0);
    }
}

template <class T>
Hexagon<T>::Hexagon(const std::vector<Point<T>>& t) {
    if (t.size() != _num_of_vertices) {
        throw std::invalid_argument("Hexagon must have exactly 6 vertices");
    }
    _vertices = t;
}

template <class T>
Hexagon<T>::Hexagon(const std::initializer_list<Point<T>>& t) {
    if (t.size() != _num_of_vertices) {
        throw std::invalid_argument("Hexagon must have exactly 6 vertices");
    }
    size_t i = 0;
    for (const Point<T>& elem : t) {
        _vertices[i] = elem;
        ++i;
    }
}

template <class T>
Hexagon<T>::Hexagon(Point<T> p1, Point<T> p2, Point<T> p3, Point<T> p4, Point<T> p5, Point<T> p6) {
    _vertices[0] = p1;
    _vertices[1] = p2;
    _vertices[2] = p3;
    _vertices[3] = p4;
    _vertices[4] = p5;
    _vertices[5] = p6;
}

template <class T>
Hexagon<T>::Hexagon(const Hexagon<T>& h) {
    _vertices = h._vertices;
}

template <class T>
Hexagon<T>::Hexagon(Hexagon<T>&& h) noexcept {
    _vertices = std::move(h._vertices);
}

template <class T>
Hexagon<T>::~Hexagon() noexcept {}

template <class T>
Point<T> Hexagon<T>::get_center() const noexcept {
    T x_sum = 0;
    T y_sum = 0;
    for (const auto& vertex : _vertices) {
        x_sum += vertex.first;
        y_sum += vertex.second;
    }
    return { x_sum / _num_of_vertices, y_sum / _num_of_vertices };
}

template <class T>
Hexagon<T>::operator double() const noexcept {
    double area = 0.0;
    for (size_t i = 0; i < _num_of_vertices; ++i) {
        size_t j = (i + 1) % _num_of_vertices;
        area += (_vertices[i].first * _vertices[j].second) - (_vertices[j].first * _vertices[i].second);
    }
    return std::abs(area) / 2.0;
}

template <class T>
bool Hexagon<T>::operator==(const Hexagon<T>& rhs) const noexcept {
    return is_eq(static_cast<double>(*this), static_cast<double>(rhs));
}

template <class T>
bool Hexagon<T>::operator!=(const Hexagon<T>& rhs) const noexcept {
    return !(*this == rhs);
}

template <class T>
bool Hexagon<T>::operator>(const Hexagon<T>& rhs) const noexcept {
    return static_cast<double>(*this) > static_cast<double>(rhs);
}

template <class T>
bool Hexagon<T>::operator>=(const Hexagon<T>& rhs) const noexcept {
    return (*this > rhs) || (*this == rhs);
}

template <class T>
bool Hexagon<T>::operator<(const Hexagon<T>& rhs) const noexcept {
    return !(*this >= rhs);
}

template <class T>
bool Hexagon<T>::operator<=(const Hexagon<T>& rhs) const noexcept {
    return !(*this > rhs);
}

template <class T>
Hexagon<T>& Hexagon<T>::operator=(const Hexagon<T>& rhs) {
    if (this != &rhs) {
        _vertices = rhs._vertices;
    }
    return *this;
}

template <class T>
Hexagon<T>& Hexagon<T>::operator=(Hexagon<T>&& rhs) noexcept {
    if (this != &rhs) {
        _vertices = std::move(rhs._vertices);
    }
    return *this;
}
