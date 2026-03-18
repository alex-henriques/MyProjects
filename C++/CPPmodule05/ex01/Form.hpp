#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat;

class Form {
    private:
        const std::string name;
        bool    sign;
        const int   gradeToSign;
        const int   gradeToExecute;

        void    validateGrade(int grade) const;

    public:
        Form(const std::string& name, int gradeToSign, int gradeToExecute); //constructor
        Form(const Form& other); //copy constructor
        Form& operator=(const Form& other); //assign. operator
        ~Form(); //destructor

        //getters
        const std::string& getName() const;
        bool    isSigned() const;
        int getGradeToExecute() const;
        int getGradeToSign() const;

        //member function
        void    beSigned(const Bureaucrat& bureaucrat);

        //Exception class
        class   GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class   GradeTooLowException : public std::exception {
            public:
                virtual const char * what() const throw();
        };

        //grade limits
        static const int    HIGHEST_GRADE = 1;
        static const int    LOWEST_GRADE = 150;

};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif