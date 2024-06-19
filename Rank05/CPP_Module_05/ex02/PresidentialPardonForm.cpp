#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : Form(other), _target(other._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this == &other)
		return *this;
	Form::operator=(other);
	_target = other._target;
	return *this;
}

std::string	PresidentialPardonForm::getTarget() const {
	return _target;
}

void	PresidentialPardonForm::be_executed(const Bureaucrat &executor) const {
	(void)executor;
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}