#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;

	Form* rrf;

	try
	{
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	if (rrf)
		delete rrf;
}