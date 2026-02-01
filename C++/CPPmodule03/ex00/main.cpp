#include "ClapTrap.hpp"
#include <iostream>

int main() {
    std::cout << "==> Constructors <==" << std::endl;
    {
        ClapTrap    clap1;
        ClapTrap    clap2("Chicken wings");
        ClapTrap    clap3(clap2);
        clap1 = clap2;
    }
    std::cout << "\n==> Basic Operations <==" << std::endl; 
    {
        ClapTrap clap1("CT-01");
        clap1.attack("target dummy");
        clap1.takeDamage(3);
        clap1.beRepaired(5);
        clap1.attack("another target");
    }
    std::cout <<  "\n==> Energy Depletion <==" << std::endl;
    {
        ClapTrap clap2("Blob");
        for (int i = 0; i < 10; i++) {
            clap2.attack("enemy");
        }
        clap2.attack("one more enemy");
        clap2.beRepaired(5);
    }
        std::cout << "\n==> Lethal Damage <==" << std::endl;
    {
        ClapTrap clap3("Alice");
        clap3.attack("target");
        clap3.takeDamage(15);
        clap3.attack("target");
        clap3.beRepaired(5);
    }
    
    std::cout << "\n==> Multiple ClapTraps <==" << std::endl;
    {
        ClapTrap clap4("Subject-Clap");
        ClapTrap clap5("Subject-trap");
        
        clap4.attack("enemy A");
        clap5.attack("enemy B");
        clap4.takeDamage(5);
        clap5.beRepaired(2);
    }
    
    std::cout << "\n==> Edge Cases <==" << std::endl;
    {
        ClapTrap clap6("Subject-00");
        clap6.attack("target1");
        clap6.attack("target2");
        clap6.beRepaired(3);
        clap6.takeDamage(7);
        clap6.attack("target3");
        clap6.beRepaired(2);
    }
    return 0;
}