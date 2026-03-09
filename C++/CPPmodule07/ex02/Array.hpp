#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array {
    private: 
        T   *_elements;
        unsigned int    _size;

    public: 
        Array();
        Array(unsigned int i);
        Array(Array const &copy);
        ~Array();

        //operators
        Array &operator=(Array const &copy);
        T &operator[](unsigned int j);
        T const &operator[](unsigned int j) const;

        unsigned int    size() const;

        class OutOfRangeException : public std::exception{
            public:
                virtual const char *what() const throw();
        };
};

#include "Array.tpp"

#endif