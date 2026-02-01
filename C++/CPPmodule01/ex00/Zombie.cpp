#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string zombieName) : name(zombieName) {
    std::cout << name << " IS ALIVE!" << std::endl;
}

Zombie::~Zombie() {
    std::cout << name << " GOT WRECKED!!" << std::endl;
}

void    Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
