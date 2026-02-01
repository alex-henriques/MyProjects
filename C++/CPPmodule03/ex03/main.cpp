#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main() {
    std::cout << "==> DiamondTrap Construction <==" << std::endl;
    {
        DiamondTrap diamond("Bob");
        std::cout << std::endl;
    }
    std::cout << "\n==> whoAmI() Function <==" << std::endl;
    {
        DiamondTrap diamond("Alice");
        diamond.whoAmI();
        std::cout << std::endl;
    }
    std::cout << "\n==> Diamond Attack <==" << std::endl;
    {
        DiamondTrap diamond("Subject01");
        diamond.attack("Dalek1");
        diamond.attack("Cyberman2");
        diamond.takeDamage(50);
        diamond.attack("WeepingAngel");
        std::cout << "\nAttacking many times to test energy..." << std::endl;
        for(int i = 0; i < 48; i++) {
            diamond.attack("WeepingAngel(enemy)");
        }
        diamond.attack("last enemy"); //succeed, still have energy
        diamond.attack("one more"); //fail -> check if correct
        std::cout << std::endl;
    }
    std::cout << "\n==> Inherited functions <==" << std::endl;
    {
        DiamondTrap diamond("Multi");
        diamond.guardGate(); //scavtrap
        diamond.highFiveGuys(); //fragtrap
        diamond.takeDamage(30); //regular function
        diamond.beRepaired(10); // regular function
        diamond.whoAmI();
        std::cout << std::endl;
    }
    std::cout << "\n==> Multiple DiamondTraps <==" << std::endl;
    {
        DiamondTrap diamond1("first");
        DiamondTrap diamond2("second");
        diamond1.whoAmI();
        diamond2.whoAmI();
        diamond1.attack("enemy A");
        diamond2.attack("enemy B");
        std::cout << std::endl;
    }
    return 0;
}