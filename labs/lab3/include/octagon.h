#pragma once
#include "figure.h"
#include <vector>

class Octagon : public Figure {
    friend std::ostream& operator<<(std::ostream& os, const Octagon & o);
    friend std::istream& operator>>(std::istream& is, Octagon & o);
public:
    Octagon();
    Octagon(const Octagon & o);
    Octagon(Octagon&& o) noexcept;
    Octagon(const std::initializer_list<Point> & t);
    Octagon(Point first, Point second, Point third, Point fourth, Point fifth, Point sixth, Point seventh, Point eighth);
    Octagon(const std::vector<Point> & t);
    ~Octagon() noexcept;
    virtual Point get_center() const override;
    virtual operator double() const override;
    bool operator==(const Octagon & rhs) const noexcept;
    bool operator!=(const Octagon & rhs) const noexcept;
    bool operator>(const Octagon & rhs) const noexcept;
    bool operator<(const Octagon & rhs) const noexcept;
    bool operator>=(const Octagon & rhs) const noexcept;
    bool operator<=(const Octagon & rhs) const noexcept;
    Octagon& operator=(const Octagon & rhs);
    Octagon& operator=(Octagon&& rhs) noexcept;
private:
    static const size_t _num_of_vertices = 8;
    std::vector<Point> _vertices = std::vector<Point>(_num_of_vertices);
};