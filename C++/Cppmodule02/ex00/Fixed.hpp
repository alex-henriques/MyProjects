#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
    private:
        int rawBits;
        static const int    fractionalBits = 8;

    public:
        Fixed(); // Default constructor
        Fixed(const Fixed& other); // copy constructor
        Fixed& operator=(const Fixed& other); //copy assignment operator
        ~Fixed(); // destructor
        int getRawBits(void) const; //member function
        void    setRawBits(int const raw);
};

#endif