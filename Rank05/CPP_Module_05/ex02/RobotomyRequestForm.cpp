#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : Form(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this == &other)
		return *this;
	Form::operator=(other);
	_target = other._target;
	return *this;
}

std::string	RobotomyRequestForm::getTarget() const {
	return _target;
}

void	RobotomyRequestForm::be_executed(const Bureaucrat &executor) const {
	(void)executor;
	std::srand(std::time(0));
	int random_number = std::rand();
	std::cout << "Trrrrr ZzzzTch Trrrrr ZzzzTch!" << std::endl;
	if (random_number % 2 == 0) {
		std::cout << "Target : " << this->getTarget() << " has been robotomized successfully!" << std::endl;
	}
	else {
		std::cout << "Target : " << this->getTarget() << " robotomization failed!" << std::endl;
	}

}
