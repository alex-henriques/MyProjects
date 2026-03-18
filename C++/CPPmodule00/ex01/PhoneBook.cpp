#include "PhoneBook.hpp"
#include <iostream>
#include <limits>

PhoneBook::PhoneBook() : count(0), index(0) {} //constructor: runs automatically when PhoneBook is created (check this, still have doubts about it)

bool    PhoneBook::addContact() {
    std::string fn, ln, nn, pn, ds;
    std::cout << "First name: ";
    std::getline(std::cin, fn);
    if (std::cin.eof()) {
        return false;
    }
    std::cout << "Last name: ";
    std::getline(std::cin, ln);
    if (std::cin.eof()) {
        return false;
    }
    std::cout << "Nickname: ";
    std::getline(std::cin, nn);
    if (std::cin.eof()) {
        return false;
    }
    std::cout << "Phone Number: ";
    std::getline(std::cin, pn);
    if (std::cin.eof()) {
        return false;
    }
    std::cout << "Darkest Secret: ";
    std::getline(std::cin, ds);
    if (std::cin.eof()) {
        return false;
    }

    contacts[index].setContact(fn, ln, nn, pn, ds);
    index = (index + 1) % 8; //after index 7 it goes straight to 0 again. ensures circular buffer that overwrites the oldest contact.
    if (count < 8)
        count++;
    std::cout << "Contact added successfully!\n";
    return true;
}

bool    PhoneBook::searchContact() const{
     if (count == 0) {
        std::cout << "No contacts stored.\n";
        return true;
    }
    std::cout << "|------------------------------------------|\n";
    std::cout << "|  Index  |First Name| Last Name| Nickname |\n";
    std::cout << "|------------------------------------------|\n";
    for(int i = 0; i < count; i++) {
        contacts[i].displayShort(i);
    }
    std::cout << "|------------------------------------------|\n";
    std::cout << "Enter index of contact to view: ";
    std::string input;
    std::getline(std::cin, input);
    if (std::cin.eof()) {
        return false;
    }
    if (input.length() != 1 || input[0] < '0' || input[0] >= '0' + count) { //validates the input. checks if it's not exactly one char long, 
                                                                           //if it's not a digit or that said digit is outside the valid range (0 to count-1)
        std::cout << "Invalid index.\n";
        return true;
    }
    int idx = input[0] - '0'; //converts the char digit to an int
    contacts[idx].displayFull();
    return true;
}
