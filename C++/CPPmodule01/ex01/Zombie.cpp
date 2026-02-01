#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : name("Unnamed") {
    std::cout <<"Zombie created (default)" << std::endl;
}

Zombie::Zombie(std::string zombieName) : name(zombieName) {
    std::cout << "Zombie " << name << " has risen" << std::endl;
}

Zombie::~Zombie() {
    std::cout << "Zombie " << name << " has fallen" << std::endl;
}

void    Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string name) {
    this->name = name;
}
