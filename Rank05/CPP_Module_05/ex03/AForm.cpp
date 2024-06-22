#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Form::Form() : _name(""), _signed(false), _sign_grade(150), _ex_grade(150) {
	std::cout << "A noname Bureaucrat has appeared." << std::endl;
}

Form::Form(std::string name, int sign_grade, int ex_grade) : _name(name), _signed(false), _sign_grade(sign_grade), _ex_grade(ex_grade) {
	if (this->_sign_grade < 1 || this->_ex_grade < 1)
		throw (Form::GradeTooHighException());
	else if (this->_sign_grade > 150 || this->_ex_grade > 150)
		throw (Form::GradeTooLowException());
	else
		std::cout << "Form " << name << " with sign grade " << sign_grade << " and exec grade " << ex_grade << " created." << std::endl;
}

Form::~Form() {
	std::cout << "Form " << _name << " has disappeared" << std::endl;
}

Form::Form(const Form &other) : _name(other._name + "_copy"), _signed(other._signed), _sign_grade(other._sign_grade), _ex_grade(other._ex_grade) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form &other) {
	std::cout << "Form Assignation operator called" << std::endl;
	if (this != &other) {
		this->_signed = other._signed;
	}
	return *this;
}

std::string Form::getName() const {
	return (this->_name);
}

bool Form::getSigned() const {
	return (this->_signed);
}

int Form::getSignGrade() const {
	return (this->_sign_grade);
}

int Form::getExecGrade() const {
	return (this->_ex_grade);
}

void	Form::beSigned(const Bureaucrat &bureaucrat) {
	if (this->_sign_grade >= bureaucrat.getGrade()) {
		this->_signed = true;
		std::cout << this->getName() << " signed status changed to true by " << bureaucrat.getName() << std::endl;
	}
	else
		throw (Form::GradeTooLowException());
}

Form	*Form::makeForm(std::string name, std::string target, int i, Form *form) {
	switch (i)
	{
	case 1:
		return (PresidentialPardonForm::makeForm(name, target, i, form));
	case 2:
		return (RobotomyRequestForm::makeForm(name, target, i,form));
	case 3:
		return (ShrubberyCreationForm::makeForm(name, target, i, form));
	}
	return (NULL);
}

void	Form::execute(const Bureaucrat &executor) const {
	if (!this->getSigned())
		throw (Form::FormNotSignedException());
	if (executor.getGrade() > this->getExecGrade())
		throw (Form::GradeTooLowException());
	else
		this->be_executed(executor);
}

char const *Form::GradeTooHighException::what(void) const throw() {
	return ("Grade is too high!");
}

char const *Form::GradeTooLowException::what(void) const throw() {
	return ("Grade is too low!");
}

char const*Form::FormNotSignedException::what(void) const throw() {
	return ("Form is not signed!");
}

std::ostream &operator<<(std::ostream &os, const Form &obj) {
	os << "Form: " << obj.getName() << " with sign grade " << obj.getSignGrade() << " and exec grade " << obj.getExecGrade() << " is " << (obj.getSigned() ? "signed" : "not signed");
	return os;
}

