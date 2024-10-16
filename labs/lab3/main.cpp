#include <iostream>
#include <cmath>
#include "triangle.h"
#include "hexagon.h"
#include "octagon.h"
#include "array.h"

void testTriangle() {
    std::cout << "=== Тестирование правильного треугольника ===" << std::endl;

    Triangle t1{{{0, 0}, {1, 0}, {0.5, std::sqrt(3) / 2}}};
    
    std::cout << "Вершины треугольника t1: " << t1 << std::endl;

    std::cout << "Площадь t1: " << static_cast<double>(t1) << std::endl;

    std::cout << "Центр треугольника t1: " << t1.get_center() << std::endl;
}

void testHexagon() {
    std::cout << "\n=== Тестирование правильного шестиугольника ===" << std::endl;

    Hexagon h1{{{0, 0}, {1, 0}, {1.5, std::sqrt(3) / 2}, {1, std::sqrt(3)}, {0, std::sqrt(3)}, {-0.5, std::sqrt(3) / 2}}};

    std::cout << "Вершины шестиугольника h1: " << h1 << std::endl;

    std::cout << "Площадь h1: " << static_cast<double>(h1) << std::endl;

    std::cout << "Центр шестиугольника h1: " << h1.get_center() << std::endl;
}

void testOctagon() {
    std::cout << "\n=== Тестирование правильного восьмиугольника ===" << std::endl;

    Octagon o1{{{0, 1}, {1, 0}, {2, 0}, {3, 1}, {3, 2}, {2, 3}, {1, 3}, {0, 2}}};

    std::cout << "Вершины восьмиугольника o1: " << o1 << std::endl;

    std::cout << "Площадь o1: " << static_cast<double>(o1) << std::endl;

    std::cout << "Центр восьмиугольника o1: " << o1.get_center() << std::endl;
}

void testArray() {
    std::cout << "\n=== Тестирование массива фигур ===" << std::endl;
    Triangle t = {{{0, 0}, {1, 0}, {0.5, std::sqrt(3) / 2}}};
    Hexagon h = {{{0, 0}, {1, 0}, {1.5, std::sqrt(3) / 2}, {1, std::sqrt(3)}, {0, std::sqrt(3)}, {-0.5, std::sqrt(3) / 2}}};
    Octagon o = {{{0, 1}, {1, 0}, {2, 0}, {3, 1}, {3, 2}, {2, 3}, {1, 3}, {0, 2}}};
    Array a = {&t, &h, &o};

    std::cout << "Размер массива: " << a.get_size() << std::endl;
    
    std::cout << "Центры фигур: ";
    a.print_centers();
    std::cout << std::endl;

    std::cout << "Площади фигур: ";
    a.print_areas();
    std::cout << std::endl;

    double total_area = a.get_total_area();
    std::cout << "Общая площадь всех фигур: " << total_area << std::endl;

    a.remove(1);

    std::cout << "\nПосле удаления второй фигуры:" << std::endl;
    std::cout << "Центры фигур: ";
    a.print_centers();
    std::cout << std::endl;

    std::cout << "Площади фигур: ";
    a.print_areas();
    std::cout << std::endl;

    std::cout << "Общая площадь всех фигур: " << a.get_total_area() << std::endl;
}

int main() {
    testTriangle();
    testHexagon();
    testOctagon();
    testArray();

    return 0;
}
