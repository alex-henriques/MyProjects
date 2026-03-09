#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _elements(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int i) : _elements(new T[i]), _size(i) {}

template <typename T>
Array<T>::Array(Array const &copy) : _elements(new T[copy._size]), _size(copy._size) {
    for (unsigned int i = 0; i < _size; i++) {
        _elements[i] = copy._elements[i];
    }
}

template <typename T>
Array<T>::~Array() {
    delete []_elements;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &copy) {
    if (this != &copy) {
        delete []_elements;
        _size = copy._size;
        _elements = new T[_size];
        for (unsigned int i = 0; i < _size; i++) {
            _elements[i] = copy._elements[i];
        }
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int i) {
    if (i >= _size) {
        throw OutOfRangeException();
    }
    return _elements[i];
}

template <typename T>
T const &Array<T>::operator[](unsigned int i) const {
    if (i >= _size) {
        throw OutOfRangeException();
    }
    return _elements[i];
}

//Methods
template <typename T>
unsigned int Array<T>::size()const {
    return _size;
}

template <typename T>
const char *Array<T>::OutOfRangeException::what() const throw() {
    return "Index out of bounds";
}

#endif