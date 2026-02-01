#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), Name("Default") {
    hit_points = FragTrap::hit_points;
    energy_points = ScavTrap::energy_points;
    attack_damage = FragTrap::attack_damage;
    max_hit_points = FragTrap::max_hit_points;
    std::cout << "DiamondTrap " << Name << " is created" << std::endl;
}

DiamondTrap::DiamondTrap(std::string Name) : ClapTrap(Name + "_clap_name"), ScavTrap(Name), FragTrap(Name), Name(Name) 
{
    hit_points = FragTrap::hit_points;
    energy_points = ScavTrap::energy_points;
    attack_damage = FragTrap::attack_damage;
    max_hit_points = FragTrap::max_hit_points;
    std::cout << "DiamondTrap " << Name << " is created!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other), Name(other.Name) {
    std::cout << "DiamondTrap " << Name << " is created with copy constructor" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    if (this != &other) {
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        Name = other.Name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << Name << " is destroyed!" << std::endl;
}

void    DiamondTrap::whoAmI() {
    std::cout << "My name is " << Name << " and my ClapTrap name is " << ClapTrap::Name << std::endl;
}