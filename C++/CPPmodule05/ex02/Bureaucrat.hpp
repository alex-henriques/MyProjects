#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class Bureaucrat {
private:
    const std::string name;
    int   grade;

    void  validateGrade(int grade) const;

public:
    Bureaucrat(const std::string& name, int grade); //Constructor
    Bureaucrat(const Bureaucrat& other);            //Copy constructor
    Bureaucrat& operator=(const Bureaucrat& other); //Assignemnt operator
    ~Bureaucrat();                                  //Destructor

    void executeForm(const AForm& form);
    void    signForm(AForm& form);

    //Getters
    const std::string& getName() const;
    int   getGrade() const;

    //Grade mod
    void  incrementGrade(); //grade nbr decreases
    void  decrementGrade();  //grade nbr increases

    //Nested exception classes
    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    //grade limits constants
    static const int HIGHEST_GRADE = 1;
    static const int LOWEST_GRADE  = 150;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif