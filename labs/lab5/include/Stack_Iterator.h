#ifndef STACK_ITERATOR_H
#define STACK_ITERATOR_H

#include <iterator>

template <typename T>
class StackIterator {
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    StackIterator(pointer ptr) : ptr_(ptr) {}

    reference operator*() const { return *ptr_; }

    pointer operator->() { return ptr_; }

    StackIterator& operator++() {
        ++ptr_;
        return *this;
    }

    StackIterator operator++(int) {
        StackIterator tmp = *this;
        ++ptr_;
        return tmp;
    }

    friend bool operator==(const StackIterator& a, const StackIterator& b) {
        return a.ptr_ == b.ptr_;
    }

    friend bool operator!=(const StackIterator& a, const StackIterator& b) {
        return a.ptr_ != b.ptr_;
    }

private:
    pointer ptr_;
};

#endif // STACK_ITERATOR_H
