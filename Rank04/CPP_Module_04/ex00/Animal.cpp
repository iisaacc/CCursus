#include "Animal.hpp"

Animal::Animal() : _type(""){
	std::cout << "A noname Animal has appeared" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "Animal " << type << " has appeared" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal " << _type << " has disappeared" << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &other) {
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

std::string	Animal::getType(void) const {
	return (_type);
}

void	Animal::setType(std::string type) {
	this->_type = type;
	std::cout << "Animal type set to " << type << std::endl;
}

void	Animal::makeSound(void) const {
	std::cout << "Animal sound" << std::endl;
}