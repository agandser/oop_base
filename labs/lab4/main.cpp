#include <iostream>
#include <memory>
#include <vector>
#include "hexagon.h"
#include "octagon.h"
#include "triangle.h"
#include "array.h"

template <typename T>
void test_array() {
    Hexagon<T> hexagon{{0, 0}, {2, 0}, {3, 1}, {2, 2}, {0, 2}, {-1, 1}};
    Octagon<T> octagon{{0, 0}, {3, 4}, {6, 0}, {3, -4}, {0, -4}, {-3, 0}, {-6, 0}, {-3, 4}};
    Triangle<T> triangle{{0, 0}, {3, 4}, {6, 0}};

    // Создаем массив фигур с использованием умных указателей
    Array<std::shared_ptr<Figure<T>>> figures = {
        std::make_shared<Hexagon<T>>(hexagon),
        std::make_shared<Octagon<T>>(octagon),
        std::make_shared<Triangle<T>>(triangle)
    };

    std::cout << "Centers of figures: ";
    figures.print_centers();

    std::cout << "Areas of figures: ";
    figures.print_areas();

    std::cout << "Total area: " << figures.get_total_area() << std::endl;

    figures.remove(1);

    std::cout << "After removing the octagon:\n";
    std::cout << "Centers of figures: ";
    figures.print_centers();
    std::cout << "Areas of figures: ";
    figures.print_areas();
    std::cout << "Total area: " << figures.get_total_area() << std::endl;
}

int main() {
    std::cout << "Testing Array with Figures\n";
    
    test_array<int>();

    return 0;
}
