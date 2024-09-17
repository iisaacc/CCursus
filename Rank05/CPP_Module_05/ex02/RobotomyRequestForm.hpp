#pragma once

#include "AForm.hpp"
#include "string"
#include "iostream"
#include <ctime>
#include <cstdlib>

class RobotomyRequestForm : public Form {
	private:
		std::string _target;

		virtual void	be_executed(const Bureaucrat &executor) const;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &other);

		std::string getTarget() const;
};