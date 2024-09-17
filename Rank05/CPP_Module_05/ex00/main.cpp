#include "Bureaucrat.hpp"

int main()
{
	try
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
		b1.incrementGrade(1);
		std::cout << b1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		//test exceptions
		Bureaucrat b3("Bureaucrat3", 160);
		std::cout << b3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;

}