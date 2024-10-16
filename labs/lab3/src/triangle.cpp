#include "triangle.h"
#include <cmath>

const double EPS = 1e-7; // Константа для погрешности

static bool is_eq(double a, double b) noexcept {
    return std::fabs(a - b) < EPS; // Сравнение с учетом погрешности
}

std::ostream& operator<<(std::ostream& output, const Triangle& triangle) {
    for (const Point& vertex : triangle._vertices) {
        output << vertex << " ";
    }
    return output;
}

std::istream& operator>>(std::istream& input, Triangle& triangle) {
    for (Point& vertex : triangle._vertices) {
        input >> vertex;
    }
    return input;
}

Triangle::Triangle() {
    for (Point& vertex : _vertices) {
        vertex = {0, 0};
    }
}

Triangle::Triangle(const Triangle& triangle) {
    _vertices = triangle._vertices;
}

Triangle::Triangle(Triangle&& triangle) noexcept {
    _vertices = std::move(triangle._vertices);
}

Triangle::Triangle(const std::initializer_list<Point>& points) {
    size_t index = 0;
    for (const Point& vertex : points) {
        _vertices[index++] = vertex;
    }
}

Triangle::Triangle(Point p1, Point p2, Point p3) {
    _vertices[0] = p1;
    _vertices[1] = p2;
    _vertices[2] = p3;
}

Triangle::Triangle(const std::vector<Point>& points) {
    _vertices = points;
}

Triangle::~Triangle() noexcept {}

Point Triangle::get_center() const {
    return {
        (_vertices[0].first + _vertices[1].first + _vertices[2].first) / 3,
        (_vertices[0].second + _vertices[1].second + _vertices[2].second) / 3
    };
}

Triangle::operator double() const {
    Point center = this->get_center();
    double ab_len_square = 
        (_vertices[1].first - _vertices[0].first) * (_vertices[1].first - _vertices[0].first) + 
        (_vertices[1].second - _vertices[0].second) * (_vertices[1].second - _vertices[0].second);
    double area = (ab_len_square * sqrt(3) / 4); // Площадь треугольника
    return area;
}

bool Triangle::operator==(const Triangle& rhs) const noexcept {
    return is_eq(static_cast<double>(*this), static_cast<double>(rhs));
}

bool Triangle::operator!=(const Triangle& rhs) const noexcept {
    return !(*this == rhs);
}

bool Triangle::operator>(const Triangle& rhs) const noexcept {
    return (static_cast<double>(*this) > static_cast<double>(rhs));
}

bool Triangle::operator<(const Triangle& rhs) const noexcept {
    return !(*this >= rhs);
}

bool Triangle::operator>=(const Triangle& rhs) const noexcept {
    return (*this > rhs) || (*this == rhs);
}

bool Triangle::operator<=(const Triangle& rhs) const noexcept {
    return !(*this > rhs);
}

Triangle& Triangle::operator=(const Triangle& rhs) {
    if (this != &rhs) {
        _vertices = rhs._vertices;
    }
    return *this;
}

Triangle& Triangle::operator=(Triangle&& rhs) noexcept {
    if (this != &rhs) {
        _vertices = std::move(rhs._vertices);
    }
    return *this;
}
