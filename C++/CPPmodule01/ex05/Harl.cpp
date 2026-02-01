#include "Harl.hpp"
#include <iostream>

void    Harl::debug(void) {
    std::cout << "I love the smell of whisky in the morning along with some good Blues!" << std::endl;
}

void    Harl::info(void) {
    std::cout << "I wish the prices weren't so high for one simple glass. If it had enough I wouldn't be asking for more...." << std::endl;
}

void    Harl::warning(void) {
    std::cout << "You think this is a game fam?" << std::endl;
}

void    Harl::error(void) {
    std::cout << "Ok as you wish darling!" << std::endl;
}

void    Harl::complain(std::string level) {
    void (Harl::*levels[]) (void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    std::string levelNames[] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };
    for(int i = 0; i < 4; i++) {
        if (levelNames[i] == level) {
            (this->*levels[i])();
            return ;
        }
    }
    std::cout << "Unknown level biatch! " << std::endl;
}