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

Fixed& Fixed::operator++() {
    this->rawBits++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed   temp(*this); //save current value
    this->rawBits++; //increment
    return temp; //return old value
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed   result;
    long long temp = static_cast<long long>(this->rawBits) * static_cast<long long>(other.rawBits);
    result.rawBits = static_cast<int>(temp >> fractionalBits);
    return result;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->rawBits = other.getRawBits();
    }
    return *this;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->rawBits < other.rawBits;
}

bool Fixed::operator>(const Fixed& other) const {
    return this->rawBits > other.rawBits;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->rawBits <= other.rawBits;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->rawBits >= other.rawBits;
}

bool Fixed::operator==(const Fixed& other) const {
    return this->rawBits == other.rawBits;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->rawBits != other.rawBits;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->rawBits = roundf(value * (1 << fractionalBits)); //multiply by 2^8 and round
} 

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { //check if I can do this otherwise do an if-else.
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
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