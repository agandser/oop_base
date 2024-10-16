#include "hexagon.h"
#include <cmath>

const double EPS = 1e-7; // Погрешность для сравнения

static bool is_eq(double a, double b) noexcept {
    return std::fabs(a - b) < EPS; // Сравнение с учётом погрешности
}

std::ostream& operator<<(std::ostream& output_stream, const Hexagon& hex) {
    for (const Point& vertex : hex._vertices) {
        output_stream << vertex << " ";
    }
    return output_stream;
}

std::istream& operator>>(std::istream& input_stream, Hexagon& hex) {
    std::vector<Point> temp_vertices(hex._num_of_vertices);
    for (Point& vertex : temp_vertices) {
        input_stream >> vertex;
    }
    hex._vertices = temp_vertices; // Обновление вершин
    return input_stream;
}

Hexagon::Hexagon() {
    for (Point& vertex : _vertices) {
        vertex = {0.0, 0.0};
    }
}

Hexagon::Hexagon(const std::vector<Point>& points) : _vertices(points) {}

Hexagon::Hexagon(const std::initializer_list<Point>& points) {
    size_t i = 0;
    for (const Point& vertex : points) {
        _vertices[i++] = vertex;
    }
}

Hexagon::Hexagon(Point p1, Point p2, Point p3, Point p4, Point p5, Point p6) {
    _vertices[0] = p1;
    _vertices[1] = p2;
    _vertices[2] = p3;
    _vertices[3] = p4;
    _vertices[4] = p5;
    _vertices[5] = p6;
}

Hexagon::Hexagon(const Hexagon& hex) {
    _vertices = hex._vertices;
}

Hexagon::Hexagon(Hexagon&& hex) noexcept {
    _vertices = std::move(hex._vertices);
}

Hexagon::~Hexagon() {}

Point Hexagon::get_center() const noexcept {
    Point center;
    center.first = (_vertices[0].first + _vertices[3].first) / 2;
    center.second = (_vertices[0].second + _vertices[3].second) / 2;
    return center;
}

Hexagon::operator double() const noexcept {
    double area = 3 * (sqrt(3) / 2) * 
                  ((_vertices[1].first - _vertices[0].first) * (_vertices[1].first - _vertices[0].first) +
                   (_vertices[1].second - _vertices[0].second) * (_vertices[1].second - _vertices[0].second));
    return area;
}

bool Hexagon::operator==(const Hexagon& rhs) const noexcept {
    return is_eq(static_cast<double>(*this), static_cast<double>(rhs));
}

bool Hexagon::operator!=(const Hexagon& rhs) const noexcept {
    return !(*this == rhs);
}

bool Hexagon::operator>(const Hexagon& rhs) const noexcept {
    return static_cast<double>(*this) > static_cast<double>(rhs);
}

bool Hexagon::operator>=(const Hexagon& rhs) const noexcept {
    return (*this > rhs) || (*this == rhs);
}

bool Hexagon::operator<=(const Hexagon& rhs) const noexcept {
    return !(*this > rhs);
}

bool Hexagon::operator<(const Hexagon& rhs) const noexcept {
    return !(*this >= rhs);
}

Hexagon& Hexagon::operator=(const Hexagon& rhs) {
    if (this != &rhs) {
        _vertices = rhs._vertices;
    }
    return *this;
}

Hexagon& Hexagon::operator=(Hexagon&& rhs) noexcept {
    if (this != &rhs) {
        _vertices = std::move(rhs._vertices);
    }
    return *this;
}
