#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>


int main() {
    std::cout << "==> Valid form creation <==" << std::endl;
    try {
        Form taxForm("Tax Form", 50, 25);
        std::cout << taxForm << std::endl;
        Form topSecret("Top Secret", 1, 1);
        std::cout << topSecret << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;


    std::cout << "==> Invalid form creation (grade too high) <==" << std::endl;
    try {
        Form invalid("Invalid", 0, 50);
        std::cout << invalid << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;


    std::cout << "==> Invalid Form Creation (grade too low) <==" << std::endl;
    try {
        Form invalid("Invalid", 50, 151);
        std::cout << invalid << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;


    std::cout << "==> Successful form signing <==" << std::endl;
    try {
        Bureaucrat bugsbunny("Bugs Bunny", 30);
        Form permit("Building Permit", 50, 25);
        std::cout << bugsbunny << std::endl;
        std::cout << permit << std::endl;
        bugsbunny.signForm(permit);
        std::cout << permit << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;


    std::cout << "==> Multiple bureaucrats, one form ===" << std::endl;
    try {
        Form contract("Employment Contract", 75, 50);
        Bureaucrat porky("Porky", 100);
        Bureaucrat lola("Lola", 50);
        std::cout << contract << std::endl;
        porky.signForm(contract);  // Should fail
        std::cout << contract << std::endl;
        lola.signForm(contract);    // Should succeed
        std::cout << contract << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;


    std::cout << "=== Test 7: Signing Already Signed Form ===" << std::endl;
    try {
        Form memo("Memo", 100, 75);
        Bureaucrat dean("Dean", 50);
        dean.signForm(memo);
        std::cout << memo << std::endl;
        dean.signForm(memo);  // Sign again
        std::cout << memo << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}