#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << "A noname WrongAnimal has appeared" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal " << this->getType() << " has disappeared" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	this->setType(other.getType());
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