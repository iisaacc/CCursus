#include "Bureaucrat.hpp"

int main()
{
	//Test all members of the Bureaucrat class here
	Bureaucrat b1("Bureaucrat1", 1);
	std::cout << b1 << std::endl;
	Bureaucrat b2("Bureaucrat2", 150);
	std::cout << b2 << std::endl;
	//test all funcitions
	b1.decrementGrade(1);
	std::cout << b1 << std::endl;
	b1.incrementGrade(1);
	std::cout << b1 << std::endl;
	try
	{
		b1.incrementGrade(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	//test exceptions
	try
	{
		Bureaucrat b3("Bureaucrat3", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b4("Bureaucrat4", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}