#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class   PhoneBook {
private:
    Contact contacts[8]; //fixed size array for the 8 contacts
    int count; //how many contacts are stored
    int index; //where the next contatc will be

public:
    PhoneBook(); //constructor
    bool    addContact();
    bool    searchContact() const;
};

#endif
