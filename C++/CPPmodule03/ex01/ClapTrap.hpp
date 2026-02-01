#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class   ClapTrap {
    protected:
        std::string Name;
        unsigned int    hit_points;
        unsigned int    energy_points;
        unsigned int    attack_damage;

    public:
        ClapTrap(); // default constructor.
        ClapTrap(std::string Name); // parameter constructor
        ClapTrap(const ClapTrap& other); //copy constructor
        ClapTrap& operator=(const ClapTrap& other); //copy assignment
        ~ClapTrap(); 

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif