#include "Functions.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <exception>

Base* generate(void) { //randomly creates one of the 3 derived classes and returns it as a Base* ptr
    static bool seed = false;
        if (!seed) {
        srand(time(NULL));
        seed = true;
    }
    int random = rand() % 3; // generates 0, 1 or 2
    switch(random) {
        case 0:
            std::cout << "[Generated A]" << std::endl;
            return new A(); //creates a on heap, returns as Base*
        case 1:
            std::cout << "[Generate B]" << std::endl;
            return new B(); //creates b on heap, returns as a Base*
        case 2:
            std::cout << "[Generate C]" << std::endl;
            return new C(); //creates c on heap, returns as Base*
        default:
            return NULL;
    }
}

void    identify(Base* p) { //identify type using ptr
    if (p == NULL) {
        std::cout << "Null ptr" << std::endl;
        return;
    }
    if (dynamic_cast<A*>(p) != NULL) {
        std::cout << "A" << std::endl;
        return;
    }
    if (dynamic_cast<B*>(p) != NULL) {
        std::cout << "B" << std::endl;
        return;
    }
    if (dynamic_cast<C*>(p) != NULL) {
        std::cout << "C" << std::endl;
        return;
    }
    std::cout << "Unknown type" << std::endl;
}

void    identify(Base& p) { //identify type using reference
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (std::exception& e) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (std::exception& e) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (std::exception& e) {}
    std::cout << "Unknown type" << std::endl;
}