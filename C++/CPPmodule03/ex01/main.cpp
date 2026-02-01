#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
    std::cout << "==> ScavTrap vs ClapTrap <==" << std::endl; 
    {
        ClapTrap clap1("NotGizmo");
        clap1.attack("target dummy");
        clap1.takeDamage(3);
        clap1.beRepaired(5);
        clap1.attack("another target");

        ScavTrap scav1("Gizmo");
        scav1.attack("target");
        scav1.guardGate();

        ScavTrap scav2("Cyberman");
        scav2.attack("Training Bot");

        ScavTrap scav3("Serena");
        std::cout << "\nDraining energy points..." << std::endl;
        for (int i = 0; i < 55; i++) {
            std::cout << "Attack " << (i + 1) << "; ";
            scav3.attack("Dummy-Serena01");
        }
    }
    std::cout << "\n==> THE END IS NIGH! - DESTRUCTION! <==" << std::endl;
    return 0;
}