#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : name(name), sign(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute){
    validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
}

Form::Form(const Form& other) : name(other.name), sign(other.sign), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        sign = other.sign;
    }
    return *this;
}

Form::~Form() {
}

//getters
const std::string& Form::getName() const {
    return name;
}

bool    Form::isSigned() const {
    return sign;
}

int Form::getGradeToSign() const {
    return gradeToSign;
}

int Form::getGradeToExecute() const {
    return gradeToExecute;
}

//validation
void    Form::validateGrade(int grade) const {
    if (grade < HIGHEST_GRADE) {
        throw GradeTooHighException();
    }
    if (grade > LOWEST_GRADE) {
        throw GradeTooLowException();
    }
}

void    Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign) {
        throw GradeTooLowException();
    }
    sign = true;
}

//exceptions
const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high.";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low.";
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
    out << "Form " << form.getName() << ", signed: " << (form.isSigned() ? "yes" : "no") << ", grade required to sign: " << form.getGradeToSign()
        << ", grade required to execute: " << form.getGradeToExecute();
    return out;
}
