#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm {
    private:
        const std::string name;
        bool    sign;
        const int   gradeToSign;
        const int   gradeToExecute;

        void    validateGrade(int grade) const;
    
    public:
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        //getters
        const std::string& getName() const;
        bool    isSigned() const;
        int getGradeToExecute() const;
        int getGradeToSign() const;

        //member functions
        void    beSigned(const Bureaucrat& bureaucrat);
        void    execute(const Bureaucrat& executor) const;

        //virtual function -> makes this class abstract
        virtual void    executeAction() const = 0;

        //Exception classes
        class   GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class   GradeTooLowException : public std::exception {
            public:
                virtual const char * what() const throw();
        };
        class FormNotSignedException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        //grade limits
        static const int    HIGHEST_GRADE = 1;
        static const int    LOWEST_GRADE = 150;
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif