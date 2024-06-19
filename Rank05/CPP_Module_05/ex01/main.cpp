#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	//Test all members of the Bureaucrat class here
	Form f1("F_1", 1, 1);
	Form f2("F_2", 150, 150);
	Bureaucrat b1 ("B_1", 1);
	Bureaucrat b2 ("B_2", 150);
	//test all funcitions
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	try
	{
		f1.beSigned(b2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	//test exceptions
	try
	{
		f1.beSigned(b1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << f1 << std::endl;
	try
	{
		Form f3("F_3", 151, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	b1.signForm(f1);
	b2.signForm(f1);
}