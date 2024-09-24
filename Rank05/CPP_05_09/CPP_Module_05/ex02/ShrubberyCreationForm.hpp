#pragma once

#include "AForm.hpp"
#include "string"
#include "iostream"

class ShrubberyCreationForm : public Form {
	private:
		std::string _target;
		virtual void	be_executed(const Bureaucrat &executor) const;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);

};