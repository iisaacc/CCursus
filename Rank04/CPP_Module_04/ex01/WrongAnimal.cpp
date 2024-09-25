#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("") {
	std::cout << "A noname WrongAnimal has appeared" << std::endl;
}

WrongAnimal::WrongAnimal(std::string const &type) : _type(type) {
	std::cout << "A noname WrongAnimal has appeared" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal " << _type << " has disappeared" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
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