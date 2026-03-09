#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h> //for uintptr
#include <iostream>
#include "Data.hpp"

class Serialization {
    private:
    Serialization();
    Serialization(const Serialization& other);
    Serialization& operator=(const Serialization& other);
    ~Serialization();

    public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif