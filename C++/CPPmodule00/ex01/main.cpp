#include "PhoneBook.hpp"
#include <iostream>

int main() {
    PhoneBook   phonebook;
    std::string command;

    std::cout << "Welcome to your PhoneBook!\n";
    std::cout << "Available commands: ADD, SEARCH, EXIT\n";

    while (true) {
        std::cout << "\nEnter command: ";
        std::getline(std::cin, command);
        if (std::cin.eof()) {
            std::cout << std::endl;
            break;
        }

        if (command == "ADD") {
            if (!phonebook.addContact()) {
                break;
            }
        }
        else if (command == "SEARCH") {
            if (!phonebook.searchContact()) {
                break;
            }
        }
        else if (command == "EXIT")
            break;
        else
            std::cout << "Unknown command. Try again.\n";
    }
    std::cout << "Goodbye!\n";
    return 0;
}