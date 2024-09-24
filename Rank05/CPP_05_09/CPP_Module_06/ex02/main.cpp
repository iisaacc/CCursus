#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>


//It randomly instanciates A, B or C and returns the instance as a Base pointer.
Base * generate(void){
	Base *base;
	int random = rand() % 3;
	if (random == 0)
		base = new A();
	else if (random == 1)
		base = new B();
	else
		base = new C();
	return base;
}

//It prints the actual type of the object pointed to by p: "A", "B" or "C".
void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

//It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer inside this function is forbidden
//In this case we use exception handling cause dynamic_cast throws an exception if the cast is not possible
void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
}


int	main()
{
	srand(static_cast<unsigned int>(time(0)));
	
	Base reference;
	Base *ptr = generate();
	std::cout << "Identified as pointer: " << std::endl;
	identify(ptr);
	std::cout << "Identified as reference: " << std::endl;
	identify(*ptr);
}