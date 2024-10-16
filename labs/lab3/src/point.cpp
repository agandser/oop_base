#include "point.h"
#include <cmath>

const double EPS = 1e-7;

bool operator==(Point x, Point y) noexcept {
    return (std::fabs(x.first - y.first) < EPS) 
    && (std::fabs(x.second - y.second) < EPS);
}

std::ostream& operator<<(std::ostream& os, const Point & c) {
    os << "(" << c.first << "; " << c.second << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Point & c) {
    is >> c.first >> c.second;
    return is;
}