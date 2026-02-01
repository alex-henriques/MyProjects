#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class   ScavTrap : virtual public ClapTrap {
    public:
        ScavTrap(); //default constructor
        ScavTrap(std::string Name); //parameter constructor
        ScavTrap(const ScavTrap& other); //copy constructor
        ScavTrap& operator=(const ScavTrap& other); //copy assignment
        ~ScavTrap();
        
        void    attack(const std::string& target);
        void    guardGate();
};

#endif