#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    max_hit_points = 100;
    std::cout << "ScavTrap " << Name << " is created with default constructor!" << std::endl;
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name) {
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    max_hit_points = 100;
    std::cout << "ScavTrap " << Name << " is created with parameter constructor!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    (void)other;
    std::cout << "ScavTrap " << Name << " is created with copy constructor!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << Name << " is destroyed!" << std::endl;
}

void    ScavTrap::attack(const std::string& target) {
    if (hit_points <= 0) {
        std::cout << "ScavTrap " << Name << " Not possible to attack " << target << std::endl;
        return;
    }
    if (energy_points <= 0) {
        std::cout << "ScavTrap " << Name << " Not possible to attack " << target << std::endl;
        return;
    }
    energy_points -= 1;
    std::cout << "ScavTrap " << Name << " Attacks " << target << std::endl;
}

void    ScavTrap::guardGate() {
    std::cout << "ScavTrap " << Name << " is now in Gate Keeper mode." << std::endl;
}
