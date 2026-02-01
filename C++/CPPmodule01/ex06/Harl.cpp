#include "Harl.hpp"
#include <iostream>

void    Harl::debug(void) {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love the smell of whisky in the morning along with some good Blues!" << std::endl;
    std::cout << std::endl;
}

void    Harl::info(void) {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I wish the prices weren't so high for one simple glass. If it had enough I wouldn't be asking for more...." << std::endl;
    std::cout << std::endl;
}

void    Harl::warning(void) {
    std::cout << "[ WARNING ]" << std:: endl;
    std::cout << "You think this is a game fam?" << std::endl;
    std::cout << std::endl;
}

void    Harl::error(void) {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "Ok as you wish darling!" << std::endl;
    std::cout << std::endl;
}

int     Harl::getLevel(std::string level) {
    if (level == "DEBUG") {
        return 0;
    }
     if (level == "INFO") {
        return 1;
    }
     if (level == "WARNING") {
        return 2;
    }
     if (level == "ERROR") {
        return 3;
    }
    return -1;
}

void    Harl::complain(std::string level) {
    int levels = getLevel(level);

    switch(levels) {
        case 0:
            debug();
            //falls through
        case 1:
            info();
            //falls through
        case 2:
            warning();
            //falls through
        case 3:
            error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}