#include "octagon.h"
#include <cmath>

const double EPS = 1e-7; // Погрешность для сравнения

static bool is_eq(double a, double b) noexcept {
    return std::fabs(a - b) < EPS; // Сравнение с учётом погрешности
}

Octagon::Octagon() {
    for (Point& vertex : _vertices) {
        vertex = {0, 0};
    }
}

Octagon::Octagon(const Octagon& oct) {
    _vertices = oct._vertices;
}

Octagon::Octagon(Octagon&& oct) noexcept {
    _vertices = std::move(oct._vertices);
}

Octagon::Octagon(const std::initializer_list<Point>& points) {
    size_t index = 0;
    for (const Point& vertex : points) {
        _vertices[index++] = vertex;
    }
}

Octagon::Octagon(Point p1, Point p2, Point p3, Point p4, Point p5, Point p6, Point p7, Point p8) {
    _vertices[0] = p1;
    _vertices[1] = p2;
    _vertices[2] = p3;
    _vertices[3] = p4;
    _vertices[4] = p5;
    _vertices[5] = p6;
    _vertices[6] = p7;
    _vertices[7] = p8;
}

Octagon::Octagon(const std::vector<Point>& points) {
    _vertices = points;
}

Octagon::~Octagon() noexcept {}

Point Octagon::get_center() const {
    Point center;
    center.first = (_vertices[0].first + _vertices[4].first) / 2; // Центр по x
    center.second = (_vertices[0].second + _vertices[4].second) / 2; // Центр по y
    return center;
}

Octagon::operator double() const {
    Point center = this->get_center();
    double radius_squared = (center.first - _vertices[0].first) * (center.first - _vertices[0].first) +
                            (center.second - _vertices[0].second) * (center.second - _vertices[0].second); // Расчет квадрата радиуса
    double area = 2 * sqrt(2) * radius_squared; // Площадь восьмиугольника
    return area;
}

std::ostream& operator<<(std::ostream& output_stream, const Octagon& oct) {
    for (const Point& vertex : oct._vertices) {
        output_stream << vertex << " ";
    }
    return output_stream;
}

std::istream& operator>>(std::istream& input_stream, Octagon& oct) {
    for (Point& vertex : oct._vertices) {
        input_stream >> vertex;
    }
    return input_stream;
}

bool Octagon::operator==(const Octagon& rhs) const noexcept {
    return is_eq(static_cast<double>(*this), static_cast<double>(rhs));
}

bool Octagon::operator!=(const Octagon& rhs) const noexcept {
    return !is_eq(static_cast<double>(*this), static_cast<double>(rhs));
}

bool Octagon::operator>(const Octagon& rhs) const noexcept {
    return static_cast<double>(*this) > static_cast<double>(rhs);
}

bool Octagon::operator>=(const Octagon& rhs) const noexcept {
    return (static_cast<double>(*this) > static_cast<double>(rhs)) || (*this == rhs);
}

bool Octagon::operator<(const Octagon& rhs) const noexcept {
    return !(*this >= rhs);
}

bool Octagon::operator<=(const Octagon& rhs) const noexcept {
    return !(*this > rhs);
}

Octagon& Octagon::operator=(const Octagon& rhs) {
    if (this != &rhs) {
        _vertices = rhs._vertices;
    }
    return *this;
}

Octagon& Octagon::operator=(Octagon&& rhs) noexcept {
    if (this != &rhs) {
        _vertices = std::move(rhs._vertices);
    }
    return *this;
}
