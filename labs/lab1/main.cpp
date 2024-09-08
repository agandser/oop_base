#include <iostream>
#include "include/isafraid.h"
#include <string>

int main()
{
    std::string day;
    int number;

    std::cout << "enter date:";
    std::cin  >> day;
    std::cout << "enter number:";
    std::cin  >> number;


    if (isafraid(day, number) == 1) {
        std::cout << "Боюсь числа!" << std::endl;
    } else if(isafraid(day, number) == 0){
        std::cout << "Не боюсь числа!" << std::endl;
    } else {
        std::cout << "У вас кривое число" << std::endl;
    }

    return 0;
}