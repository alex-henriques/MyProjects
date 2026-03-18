#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    std::cout << "==> Valid Bureaucrat creation <=="  << std::endl;
    try {
        Bureaucrat blob("Blob", 50);
        std::cout << blob << std::endl;

        Bureaucrat lucifer("Lucifer", 1);
        std::cout << lucifer << std::endl;

        Bureaucrat pantufas("Pantufas", 150);
        std::cout << pantufas << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "==> Invalid Bureaucrat creation (grade too high) <==" << std::endl;
    try {
        Bureaucrat cubi("Cubi", 0);
        std::cout << cubi << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "==> Invalid Bureaucrat creation (grade too low) <==" << std::endl;
    try {
        Bureaucrat gizmo("Gizmo", 151);
        std::cout << gizmo << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "==> Incrementing grade (promotion) <==" << std::endl;
    try {
        Bureaucrat dalek("Dalek", 5);
        std::cout << "Before: " << dalek << std::endl;

        dalek.incrementGrade();
        std::cout << " After incrementing: " << dalek << std::endl;
        dalek.incrementGrade();
        std::cout << "After second incrementation: " << dalek << std::endl;
    } catch(std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "==> Decrementing grade (demotion) <==" << std::endl;
    try {
        Bureaucrat dalek("Dalek", 5);
        std::cout << "Before: " << dalek << std::endl;

        dalek.decrementGrade();
        std::cout << " After demoting: " << dalek << std::endl;
        dalek.decrementGrade();
        std::cout << "After second demotion: " << dalek << std::endl;
    } catch(std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "==> Increment beyond the limits <==" << std::endl;
    try {
        Bureaucrat henry("Henry", 1);
        std::cout << "Before: " << henry << std::endl;
        henry.incrementGrade();
        std::cout << "After increment: " << henry << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

     std::cout << "==> Decrement beyond the limits <==" << std::endl;
    try {
        Bureaucrat henry("Henry", 150);
        std::cout << "Before: " << henry << std::endl;
        henry.decrementGrade();
        std::cout << "After decrement: " << henry << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}
