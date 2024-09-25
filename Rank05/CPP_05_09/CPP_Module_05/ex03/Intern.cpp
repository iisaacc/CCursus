#include "Intern.hpp"
#include "AForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &copy) {
	*this = copy;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &copy) {
	(void)copy;
	return *this;
}

Form	*Intern::makeForm(std::string formName, std::string target) {
	Form	*form;
	int		i;

	i = 1;
	form = NULL;
	while (!form && i < 4)
	{
		form = Form::makeForm(formName, target, i, form);
		i++;
	}
	if (!form)
		throw (Intern::FormNotFoundException());
	else
		std::cout << "Intern creates " << form->getName() << std::endl;
	return (form);
}