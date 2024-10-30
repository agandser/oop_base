#pragma once
#include "figure.h"
#include <memory>
#include <concepts>

template <class T>
class Array {
public:
    Array();
    Array(const std::initializer_list<T>& init_list);
    Array(const Array<T>& other);
    Array(Array<T>&& other) noexcept;
    ~Array();

    void remove(size_t ind);
    double get_total_area() const;
    size_t get_size() const noexcept;
    void print_centers() const;
    void print_areas() const;

private:
    std::shared_ptr<T[]> data_;
    size_t size_;
};

template <class T>
Array<T>::Array() : size_{0}, data_{nullptr} {}

template <class T>
Array<T>::Array(const std::initializer_list<T>& init_list) {
    size_ = init_list.size();
    data_ = std::make_shared<T[]>(size_);
    size_t i = 0;
    for (const auto& element : init_list) {
        data_[i++] = element;
    }
}

template <class T>
Array<T>::Array(const Array<T>& other) {
    size_ = other.size_;
    data_ = std::make_shared<T[]>(size_);
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
}

template <class T>
Array<T>::Array(Array<T>&& other) noexcept 
    : data_(std::move(other.data_)), size_(other.size_) {
    other.size_ = 0;
}

template <class T>
Array<T>::~Array() {
    size_ = 0;
}

template <class T>
double Array<T>::get_total_area() const {
    double area_sum = 0;
    for (size_t i = 0; i < size_; ++i) {
        area_sum += static_cast<double>(*(data_[i]));
    }
    return area_sum;
}

template <class T>
size_t Array<T>::get_size() const noexcept {
    return size_;
}

template <class T>
void Array<T>::remove(size_t ind) {
    if (ind >= size_) {
        throw std::out_of_range("Index out of range");
    }
    auto new_data = std::make_shared<T[]>(size_ - 1);
    for (size_t i = 0, j = 0; i < size_; ++i) {
        if (i != ind) {
            new_data[j++] = data_[i];
        }
    }
    data_ = new_data;
    --size_;
}

template <class T>
void Array<T>::print_centers() const {
    for (size_t i = 0; i < size_; ++i) {
        std::cout << data_[i]->get_center() << " ";
    }
    std::cout << std::endl;
}

template <class T>
void Array<T>::print_areas() const {
    for (size_t i = 0; i < size_; ++i) {
        std::cout << static_cast<double>(*(data_[i])) << " ";
    }
    std::cout << std::endl;
}
