#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string> 

class   FragTrap : public ClapTrap {
    public:
        FragTrap(); //default constructor
        FragTrap(std::string Name); //paramenter constructor
        FragTrap(const FragTrap& other); //copy constructor
        FragTrap& operator=(const FragTrap& other);
        ~FragTrap();
        
        void    highFiveGuys(void);
};

#endif