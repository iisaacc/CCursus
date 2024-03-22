#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : oldest(0) {
}
PhoneBook::~PhoneBook(){
}
void	PhoneBook::Search(){
		std::string	index;
		std::cout << "Introduce the contact id [0 - 7]" << std::endl;
		std::getline(std::cin, index);
		if (index.size() == 1 && index[0] >= '0' && index[0] <= '7'){
			std::cout << "   index  |first name|last name | nickname |" << std::endl;
			std::cout << "    " << index << "     |";
				contacts[index[0] - '0'].contact_print();
			std::cout << std::endl;
		}
		else{
			std::cout << "Contact id out of range. Range is [0 - 7]" << std::endl;
		}
}

void	PhoneBook::Add(){
	std::string str;
	int	idx = 0;
	for (int i = 0; i < 8; i++){
		if (contacts[i].get_fname() == ""){
			idx = i;
			break;
		}
		idx = i;
	}
	if (idx == 7 && contacts[idx].get_fname() != ""){
		std::cout << "Phonebook is full, overwriting oldest one" << std::endl;
		idx = oldest;
		oldest++;
	}
	std::cout << "Enter first name: ";
	std::getline(std::cin, str);
	contacts[idx].set_fname(str);
	std::cout << "Enter last name: ";
	std::getline(std::cin, str);
	contacts[idx].set_lname(str);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, str);
	contacts[idx].set_nick(str);
	std::cout << "Enter secret: ";
	std::getline(std::cin, str);
	contacts[idx].set_secret(str);
	std::cout << "Enter number: ";
	std::getline(std::cin, str);
	contacts[idx].set_number(str);
}
