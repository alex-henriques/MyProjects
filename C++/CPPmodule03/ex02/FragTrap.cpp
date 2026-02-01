#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    max_hit_points = 100;
    std::cout << "FragTrap " << Name << " is alive!" << std::endl;
}

FragTrap::FragTrap(std::string Name) : ClapTrap(Name)
{
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    max_hit_points = 100;
    std::cout << "FragTrap " << Name << " is alive!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "Fragtrap " << Name << " is created with copy constructor" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FragTrap assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << Name << " ... He ... RIP'D in pepperoni!! *sad face*" << std::endl;
}

void    FragTrap::highFiveGuys(void) {
    std::cout << "FragTrap " << Name << "HIGH 5 me meatbag!" << std::endl;
}
