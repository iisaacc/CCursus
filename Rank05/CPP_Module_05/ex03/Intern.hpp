#pragma once

#include "AForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern &copy);
	~Intern();
	Intern &operator=(const Intern &copy);

	Form	*makeForm(std::string name, std::string target);

	class FormNotFoundException : public std::exception {
		virtual const char *what() const throw() {
			return ("Form not found");
		}
	};

};