#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	//Test all members of the Bureaucrat class here
	ShrubberyCreationForm Sh1("home");
	ShrubberyCreationForm Sh2("garden");
	Bureaucrat B1("B1", 138);
	try {
		Sh1.execute(B1);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat B2("B2", 1);
	B2.signForm(Sh1);

	try {
		Sh1.execute(B1);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Sh1.execute(B2);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;
	PresidentialPardonForm P1("home");
	B2.signForm(P1);
	try {
		P1.execute(B2);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;
	RobotomyRequestForm R1("home");
	B2.signForm(R1);
	try {
		R1.execute(B2);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;

	Bureaucrat B3("B3", 1);
	try {
		B3.executeForm(Sh1);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat B4("B4", 150);
	try {
		B4.executeForm(P1);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;
}