#include "include/Hex.h"
#include <iostream>
#include <string>

int main() {
    std::string input1, input2;
    std::string operation;

    std::cout << "Введите первое шестнадцатеричное число: ";
    std::cin >> input1;
    std::cout << "Введите второе шестнадцатеричное число: ";
    std::cin >> input2;
    std::cout << "Выберите операцию (+, -, ==, !=, <, >, <=, >=): ";
    std::cin >> operation;

    Hex num1(input1);
    Hex num2(input2);

    if (operation == "+") {
        Hex result = num1.add(num2);
        std::cout << "Результат сложения: " << result.getvalue() << std::endl;
    } else if (operation == "-") {
        Hex result = num1.subtract(num2);
        std::cout << "Результат вычитания: " << result.getvalue() << std::endl;
    } else if (operation == "==") {
        std::cout << (num1.is_equal(num2) ? "Числа равны" : "Числа не равны") << std::endl;
    } else if (operation == "!=") {
        std::cout << (num1.is_not_equal(num2) ? "Числа не равны" : "Числа равны") << std::endl;
    } else if (operation == "<") {
        std::cout << (num1.is_less(num2) ? "Первое число меньше второго" : "Первое число не меньше второго") << std::endl;
    } else if (operation == ">") {
        std::cout << (num1.is_greater(num2) ? "Первое число больше второго" : "Первое число не больше второго") << std::endl;
    } else if (operation == "<=") {
        std::cout << (num1.is_less_or_equal(num2) ? "Первое число меньше или равно второму" : "Первое число больше второго") << std::endl;
    } else if (operation == ">=") {
        std::cout << (num1.is_greater_or_equal(num2) ? "Первое число больше или равно второму" : "Первое число меньше второго") << std::endl;
    } else {
        std::cout << "Неверная операция" << std::endl;
    }
    
    return 0;
}
