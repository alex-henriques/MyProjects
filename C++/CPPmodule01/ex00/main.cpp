#include "Zombie.hpp"
#include <iostream>

int main() {
    std::cout << "\n==> INFECTED ZONE 1: randomChump (STACK) <==" << std::endl;
    randomChump("Eugene");
    std::cout << "Eugene has finally moved on, amen" << std::endl;

    std::cout << "\n==> INFECTED ZONE 2: newZombie (HEAP) <==" << std::endl;
    Zombie *heapZombie = newZombie("Suckerino");
    heapZombie->announce();
    std::cout << "\nSuckerino is still in memory, eating brains... or something" << std::endl;
    delete heapZombie;

    std::cout << "\n==> Green Zone, clear of infection <==\n" << std:: endl;
    return 0;
}