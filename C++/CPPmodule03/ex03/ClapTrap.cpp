#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : Name("Default"),  hit_points(10), energy_points(10), attack_damage(0), max_hit_points(10) {
    std::cout << "ClapTrap " << Name << " is created with default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string Name) : Name(Name), hit_points(10), energy_points(10), attack_damage(0), max_hit_points(10) {
    std::cout << "ClapTrap " << Name << " is created with parameter constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : Name(other.Name), hit_points(other.hit_points), energy_points(other.energy_points), 
                                            attack_damage(other.attack_damage), max_hit_points(other.max_hit_points) {
    std::cout << "ClapTrap " << Name << " is created with copy constructor" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "Claptrap assignment operator called" << std::endl;
    if (this != &other) {
        Name = other.Name;
        hit_points = other.hit_points;
        energy_points = other.energy_points;
        attack_damage = other.attack_damage;
        max_hit_points = other.max_hit_points;
    }
    return *this;
}

void    ClapTrap::attack(const std::string& target) {
    if (hit_points <= 0) {
        std::cout << "ClapTrap " << Name << " can't attack, no hit points!" << std::endl;
        return ;
    }
    if (energy_points <= 0) {
        std::cout << "ClapTrap " << Name << " can't attack, no energy!" << std::endl;
        return ;
    }
    energy_points--;
    std::cout << "ClapTrap " << Name << " attacks " << target 
              << ", causing " << attack_damage << " points of damage!" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount) {
    if (amount >= hit_points) {
        hit_points = 0;
    } else {
        hit_points -= amount;
    }
    std::cout << "ClapTrap " << Name << " takes " << amount << " points of damage! Hit points now: " << hit_points << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount) {
    if (hit_points <= 0) {
        std::cout << "ClapTrap " << Name << " can't be repaired, it's destroyed!" << std::endl;
        return ;
    }
    if (energy_points <= 0) {
        std::cout << "ClapTrap " << Name << " can't be repaired, no energy!" << std::endl;
        return ;
    }
    energy_points -= 1;
    hit_points += amount;
    if (hit_points > max_hit_points) { //added for the max hit points. remove if not needed.
        hit_points = max_hit_points;
    }
    std::cout << "ClapTrap " << Name << " is repaired for " << amount << " points! Hit points now: " << hit_points << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << Name << " is destroyed!" << std::endl;
}
