#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <ostream>

Fixed::Fixed() : rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : rawBits(other.getRawBits()) {
    std::cout << "Copy constructor called" << std::endl;
    //this->rawBits = other.getRawBits();
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    this->rawBits = value << fractionalBits; //multiply by 2^8 (left shift by 8)
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->rawBits = other.getRawBits();
    }
    return *this;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->rawBits = roundf(value * (1 << fractionalBits)); //multiply by 2^8 and round
} 


Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt(void) const {
    return this->rawBits >> fractionalBits; //multiply by 2^8 (right shift by 8)
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->rawBits) / (1 << fractionalBits);
}

int Fixed::getRawBits(void) const {
    //std::cout << "getRawBits member function called" << std::endl;
    return this->rawBits;
}

void  Fixed::setRawBits(int const raw) {
    this->rawBits = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}