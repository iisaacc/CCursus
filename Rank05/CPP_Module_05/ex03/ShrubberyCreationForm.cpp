#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : Form(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this == &other)
		return *this;
	Form::operator=(other);
	_target = other._target;
	return *this;
}

void	ShrubberyCreationForm::be_executed(const Bureaucrat &executor) const {
	(void)executor;
	std::string	filename = _target + "_shrubbery";
	std::ofstream File(filename.c_str());

	File << "       _-_\n    /~~   ~~\\ \n /~~         ~~\\\n{               }\n \\  _-     -_  /\n    ~  \\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\\\n";
	File << "       _-_\n    /~~   ~~\\ \n /~~         ~~\\\n{               }\n \\  _-     -_  /\n    ~  \\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\\\n";
	File << "       _-_\n    /~~   ~~\\ \n /~~         ~~\\\n{               }\n \\  _-     -_  /\n    ~  \\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\\\n";
	File << "       _-_\n    /~~   ~~\\ \n /~~         ~~\\\n{               }\n \\  _-     -_  /\n    ~  \\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\\\n";
	File.close();
}

Form	*ShrubberyCreationForm::makeForm(std::string name, std::string target, int i, Form *form) {
	(void)i;
	(void)form;
	if (name == "shrubbery creation")
		return (new ShrubberyCreationForm(target));
	return (NULL);
}
