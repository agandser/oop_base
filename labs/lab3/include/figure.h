#pragma once
#include <iostream>
#include "point.h"

class Figure {
public:
    Figure();
    ~Figure();
    virtual Point get_center() const = 0;
    virtual operator double() const = 0;
};