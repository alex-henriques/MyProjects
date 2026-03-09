#include "Functions.hpp"
#include "Base.hpp"
#include <iostream>

int main() {
    std::cout << "Random generation" << std::endl;
    Base* obj1 = generate();
    std::cout << "identify ptr: ";
    identify(obj1);
    std::cout << "identify ref: ";
    identify(*obj1);
    delete obj1;
    std::cout << std::endl;

    std::cout << "More random generation" << std::endl;
    Base* obj2 = generate();
    std::cout << "identify ptr: ";
    identify(obj2);
    std::cout << "identify ref: ";
    identify(*obj2);
    delete obj2;
    std::cout << std::endl;

    std::cout << "Specific types" << std::endl;
    Base* a = new A();
    Base* b = new B();
    Base* c = new C();
    std::cout << "identifying ptr (A): ";
    identify(a);
    std::cout << "identifying ref (A): ";
    identify(*a);
    std::cout << "identifying ptr (B): ";
    identify(b);
    std::cout << "identifying ref (B): ";
    identify(*b);
    std::cout << "identifying ptr (C): ";
    identify(c);
    std::cout << "identifying ref (C): ";
    identify(*c);
    delete a;
    delete b;
    delete c;

    return 0;
}