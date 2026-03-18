#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : name(name), sign(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
}

AForm::AForm(const AForm& other) : name(other.name), sign(other.sign), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
}

AForm& AForm::operator=(const AForm& other) {
    if (this!= &other) {
        sign = other.sign;
    }
    return *this;
}

AForm::~AForm() {

}

const std::string& AForm::getName() const {
    return name;
}

bool AForm::isSigned() const {
    return sign;
}

int AForm::getGradeToSign() const {
    return gradeToSign;
}

int AForm::getGradeToExecute() const {
    return gradeToExecute;
}

void    AForm::validateGrade(int grade) const {
    if (grade < HIGHEST_GRADE) {
        throw GradeTooHighException();
    }
    if (grade > LOWEST_GRADE) {
        throw GradeTooLowException();
    }
}

void    AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign) {
        throw GradeTooLowException();
    }
    sign = true;
}

void AForm::execute(const Bureaucrat& executor) const {
    if (!sign) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > gradeToExecute) {
        throw GradeTooLowException();
    }
    executeAction(); // call the virtual function.
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed";
}

std::ostream& operator<<(std::ostream& out, const AForm& form) {
    out << "Form " << form.getName() << ", signed: " << (form.isSigned() ? "yes" : "no") << ", grade required to sign: " << form.getGradeToSign()
        << ", grade required to execute: " << form.getGradeToExecute();
    return out;
}