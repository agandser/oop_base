#pragma once
#include "figure.h"
#include <vector>

class Triangle : public Figure {
    friend std::ostream& operator<<(std::ostream& os, const Triangle & t);
    friend std::istream& operator>>(std::istream& is, Triangle & t);
public:
    Triangle();
    Triangle(const Triangle & t);
    Triangle(Triangle&& t) noexcept;
    Triangle(const std::initializer_list<Point> & t);
    Triangle(Point first, Point second, Point third);
    Triangle(const std::vector<Point> & t);
    ~Triangle() noexcept;
    virtual Point get_center() const override;
    virtual operator double() const override;
    bool operator==(const Triangle & rhs) const noexcept;
    bool operator!=(const Triangle & rhs) const noexcept;
    bool operator>(const Triangle & rhs) const noexcept;
    bool operator<(const Triangle & rhs) const noexcept;
    bool operator>=(const Triangle & rhs) const noexcept;
    bool operator<=(const Triangle & rhs) const noexcept;
    Triangle& operator=(const Triangle & rhs);
    Triangle& operator=(Triangle&& rhs) noexcept;
private:
    static const size_t _num_of_vertices = 3;
    std::vector<Point> _vertices = std::vector<Point>(_num_of_vertices);
};