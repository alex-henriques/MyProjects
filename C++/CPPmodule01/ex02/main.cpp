#include <iostream>
#include <string>

int main() {
    std::string brain = "HI THIS IS BRAIN";
    std::string* stringPTR = &brain;
    std::string& stringREF = brain;

    std::cout << "==> Memory addresses <==" << std::endl;
    std::cout << "Memory address of the string variable: " << &brain << std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &brain << std::endl;
    std::cout << std::endl;

    std::cout << "==> Values <==" << std::endl;
    std::cout << "Value of the string variable: " << brain << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl; 
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
    return 0;
}