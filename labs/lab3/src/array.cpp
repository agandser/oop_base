#include "array.h"

Array::Array() : _size{0}, _data{nullptr} {}

Array::Array(const std::initializer_list<Figure*> & figures) {
    _size = figures.size();
    _data = new Figure*[_size];
    size_t i = 0;
    for (Figure* figure : figures) {
        _data[i] = figure;
        ++i;
    }
}

Array::Array(const Array & other) {
    _size = other._size;
    _data = new Figure*[_size];
    for (size_t i = 0; i < _size; ++i) {
        _data[i] = other._data[i];
    }
}

Array::Array(Array&& other) noexcept {
    _data = other._data;
    _size = other._size;
    other._data = nullptr;
    other._size = 0;
}

Array::~Array() {
    delete[] _data;
    _size = 0;
}

double Array::get_total_area() const {
    double totalArea = 0;
    for (size_t i = 0; i < _size; ++i) {
        totalArea += static_cast<double>(*_data[i]);
    }
    return totalArea;
}

size_t Array::get_size() const noexcept {
    return _size;
}

void Array::remove(size_t idx) {
    if (idx >= _size) {
        throw std::range_error("i out of range");
    }
    Figure** newData = new Figure*[_size - 1];
    size_t j = 0;
    for (size_t i = 0; i < _size; ++i) {
        if (i == idx) {
            continue; // Пропустить элемент для удаления
        }
        newData[j] = _data[i];
        ++j;
    }
    --_size;
    delete[] _data;
    _data = newData;
}

void Array::print_centers() const {
    for (size_t i = 0; i < _size; ++i) {
        std::cout << _data[i]->get_center() << " ";
    }
}

void Array::print_areas() const {
    for (size_t i = 0; i < _size; ++i) {
        std::cout << static_cast<double>(*_data[i]) << " ";
    }
}
