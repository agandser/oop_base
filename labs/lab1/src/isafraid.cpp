#include "../include/isafraid.h"

int isafraid(const std::string& dayOfWeek, int number) {
    if (dayOfWeek == "Понедельник") {
        return number == 12;
    } else if (dayOfWeek == "Вторник") {
        return number > 95;
    } else if (dayOfWeek == "Среда") {
        return number == 34;
    } else if (dayOfWeek == "Четверг") {
        return number == 0;
    } else if (dayOfWeek == "Пятница") {
        return number % 2 == 0;
    } else if (dayOfWeek == "Суббота") {
        return number == 56;
    } else if (dayOfWeek == "Воскресенье") {
        return number == 666 || number == -666;
    } else {
        return -1;
    }
}