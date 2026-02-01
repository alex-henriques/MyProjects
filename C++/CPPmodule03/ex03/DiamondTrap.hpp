#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class   DiamondTrap : public ScavTrap, public FragTrap {
    private:
        std::string Name;
    public:
        DiamondTrap();
        DiamondTrap(std::string Name);
        DiamondTrap(const DiamondTrap& other);
        DiamondTrap& operator=(const DiamondTrap& other);
        ~DiamondTrap();

        
        void    whoAmI(); //displays both ClapTrap's and DiamondTrap's name
        using ScavTrap::attack;
};

#endif