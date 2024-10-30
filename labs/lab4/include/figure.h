#pragma once
#include <iostream>
#include "point.h"

template <class T>
requires std::is_convertible_v<T, double>
class Figure {
public:
    Figure() {};
    ~Figure() {};
    virtual Point<T> get_center() const = 0;
    virtual operator double() const = 0;
};