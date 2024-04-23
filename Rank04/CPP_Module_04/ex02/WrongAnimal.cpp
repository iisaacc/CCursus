#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
}

WrongAnimal::~WrongAnimal() {
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimal sound" << std::endl;
}

void	WrongAnimal::setType(std::string type) {
	this->_type = type;
}

std::string	WrongAnimal::getType(void) const {
	return this->_type;
}