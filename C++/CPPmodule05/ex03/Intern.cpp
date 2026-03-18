
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern hired" << std::endl;
}

Intern::Intern(const Intern& other) {
    (void)other;
    std::cout << "Intern (copy) hired" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern fired" << std::endl;
}

AForm* Intern::createShrubberyForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createPresidentialForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    //array of form names
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    //array of function pointers to form creators
    AForm*(Intern::*formCreators[3])(const std::string&) = {
        &Intern::createShrubberyForm,
        &Intern::createRobotomyForm,
        &Intern::createPresidentialForm
    };
    //search for the form name and create it
    for(int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formCreators[i])(target);
        }
    }
    std::cout << "Intern couldn't create form: " << formName << " (Unknown form type)" << std::endl;
    throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw() {
    return "Form type not found.";
}