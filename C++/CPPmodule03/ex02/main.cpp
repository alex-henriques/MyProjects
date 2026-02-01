#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main() {
    std::cout << "\n==>FragTrap in the house <==" << std::endl; 
    {
        FragTrap lilfrog("Gizmo");
        lilfrog.attack("target dummy");
        lilfrog.takeDamage(3);
        lilfrog.beRepaired(5);
        lilfrog.attack("another target");
    }
    
    std::cout << "\n==> THE END IS NIGH! - DESTRUCTION! <==" << std::endl;
    return 0;
}