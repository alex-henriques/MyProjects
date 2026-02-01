#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class   Contact {
private: //details for each contact
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    void    setContact(std::string firstName, std::string lastName, std::string nickname, 
        std::string phoneNumber, std::string darkestSecret); //set all the info at once
    void    displayShort(int index) const; //print a short version for SEARCH
    void    displayFull() const; //print full details
};

#endif