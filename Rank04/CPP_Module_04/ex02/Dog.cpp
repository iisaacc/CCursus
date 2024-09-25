#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "A noname Dog has appeared" << std::endl;
}

Dog::Dog(std::string type) : Animal(type) {
	std::cout << "Dog with type " << type << " has appeared" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog " << this->getType() << " has disappeared" << std::endl;
}

Dog::Dog(const Dog &other) {
	*this = other;
}

Dog &Dog::operator=(const Dog &other) {
	this->setType(other.getType());
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "Dogs talk, and human are their best friend. Wasn't like that?" << std::endl;
}