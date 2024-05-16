#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "A noname Cat has appeared" << std::endl;
}

Cat::Cat(std::string type) : Animal(type) {
	std::cout << "Cat with type " << type << " has appeared" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat " << this->getType() << " has disappeared" << std::endl;
}

Cat::Cat(const Cat &other) {
	*this = other;
}

Cat &Cat::operator=(const Cat &other) {
	this->setType(other.getType());
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "Grrrrr, miaaau" << std::endl;
}