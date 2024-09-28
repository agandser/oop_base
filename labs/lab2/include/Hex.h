#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <exception>
#include <math.h>

int CharToInt(unsigned char value);
char IntToChar(int value);
bool IsHex(unsigned char value);

class Hex {
    private:
        size_t size;
        size_t capacity;
        unsigned char* digits;

        // Приватный метод реаллокации массива
        void reallocate(const size_t& newcapacity);
    public:
        // Конструкторы
        Hex();
        Hex(const size_t& n, unsigned char t);
        Hex(const std::initializer_list<unsigned char>& t);
        Hex(const std::string& t);
        Hex(const Hex& other);
        Hex(Hex&& other) noexcept;

        // Дополнительные методы
        size_t getsize() const;
        size_t HexToDecimal() const;
        std::string getvalue() const;

        // Деструктор
        virtual ~Hex() noexcept;

        // Оператор сдвига
        friend std::ostream& operator << (std::ostream& out, Hex& obj);

        // Арифметические методы
        Hex& copy(const Hex&);             // Метод копирования
        Hex& move(Hex&&);                  // Метод перемещения
        Hex add(const Hex&) const;         // Метод сложения
        Hex subtract(const Hex&) const;    // Метод вычитания
        Hex& add_assign(const Hex&);       // Метод +=
        Hex& subtract_assign(const Hex&);  // Метод -=

        // Методы сравнения
        bool is_equal(const Hex&) const;
        bool is_not_equal(const Hex&) const;
        bool is_less(const Hex&) const;
        bool is_less_or_equal(const Hex&) const;
        bool is_greater(const Hex&) const;
        bool is_greater_or_equal(const Hex&) const;
};