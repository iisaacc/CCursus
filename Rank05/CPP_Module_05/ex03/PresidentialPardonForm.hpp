#pragma once

#include "AForm.hpp"
#include "string"
#include "iostream"

class PresidentialPardonForm : public Form {
	private:
		std::string _target;
		virtual void	be_executed(const Bureaucrat &executor) const;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &other);

		std::string getTarget() const;
		static Form *makeForm(std::string name, std::string target, int i, Form *form);
};