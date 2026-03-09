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
        ~Fixed(); // destructor

        int toInt(void) const;
        float   toFloat(void) const;
        int getRawBits(void) const; //member function
        void    setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif