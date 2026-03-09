#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <ostream>

class Fixed {
    private:
        int rawBits;
        static const int    fractionalBits = 8;

    public:
        Fixed(); // Default constructor
        Fixed(const Fixed& other); // copy constructor
        Fixed(const int value);
        Fixed(const float value);
        Fixed& operator=(const Fixed& other); //copy assignment operator
        Fixed operator*(const Fixed& other) const; // multiplies 2 fixed point nrs correctly by adjusting for the doubled fractional bits
        ~Fixed(); // destructor

        int toInt(void) const;
        float   toFloat(void) const;
        int getRawBits(void) const; //member function
        void    setRawBits(int const raw);

        //increment
        Fixed& operator++(); //prefix increment(++x) -> returns reference to incremented value
        Fixed operator++(int); //postfix increment (x++) -> returns old value then increments

        //comparision
        bool operator<(const Fixed& other) const;
        bool operator>(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& othet) const;

        //static min/max functions -> member functions that use the comparision operators to return the smaller/larger value
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif