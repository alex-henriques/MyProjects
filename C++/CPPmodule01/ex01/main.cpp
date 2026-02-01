#include "Zombie.hpp"
#include <iostream>

int main() {
    std::cout << "\n==> Horde of 5 Zombies <==" << std::endl;
    int hordeSize = 5;
    Zombie* horde = zombieHorde(hordeSize, "Boris");

    std::cout << "\n==> All Zombies <==" << std::endl;
    for (int i = 0; i < hordeSize; i++) {
        std::cout << "Zombie " << i << ": ";
        horde[i].announce();
    }

    std::cout << "\n==> Horde of 5 Zombies with different names <==" << std::endl;
    Zombie* horde1 = zombieHorde(5, "Temp");
    horde1[0].setName("Boris");
    horde1[1].setName("Ed");
    horde1[2].setName("Bob");
    horde1[3].setName("Wigglyjaw");
    horde1[4].setName("Boney");

    std::cout << "\n==> All Zombies <==" << std::endl;
    for (int i = 0; i < hordeSize; i++) {
        std::cout << "Zombie " << i << ": ";
        horde1[i].announce();
    }

    std::cout << "\n==> Cleaning this mess up... <==" << std::endl;
    delete[] horde;
    std::cout << std::endl;
    delete[] horde1;

    std::cout << "\n==> Yellow Zone: Tests completed <==" << std::endl;
    return 0;
}