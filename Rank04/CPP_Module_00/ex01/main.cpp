#include "PhoneBook.hpp"
#include <iostream>

int main()
{
	PhoneBook	phoneBook;
	std::string	command;

	std::cout << "Welcome to your Nokia de confianza!" << std::endl << std::endl;
	while (1)
	{
		std::cout << "Enter a command:	[ADD] [SEARCH] [EXIT]" << std::endl;
		std::getline(std::cin, command);
		if (command == "EXIT")
			break;
		else if (command == "ADD")
			phoneBook.Add();
		else if (command == "SEARCH")
			phoneBook.Search();
		else
			std::cout << "Invalid command" << std::endl;
	}
	return 0;
}