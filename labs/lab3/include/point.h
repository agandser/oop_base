#pragma once

#include <iostream>

typedef std::pair<double, double> Point;

bool operator==(Point x, Point y) noexcept;
std::ostream& operator<<(std::ostream& os, const Point & c);
std::istream& operator>>(std::istream& is, Point & c);