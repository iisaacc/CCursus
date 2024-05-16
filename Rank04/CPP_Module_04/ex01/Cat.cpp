#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	this->brain = new Brain();
	std::cout << "A noname Cat has appeared" << std::endl;
}

Cat::Cat(std::string type) : Animal(type) {
	std::cout << "Cat with type " << type << " has appeared" << std::endl;
}

Cat::~Cat() {
	delete this->brain;
	std::cout << "Cat has been deleted" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	this->brain = new Brain(*other.brain);
	std::cout << "Cat has been copied" << std::endl;
}

Cat	&Cat::operator=(const Cat &other) {
	if (this == &other)
		return (*this);
	Animal::operator=(other);
	delete this->brain;
	this->brain = new Brain(*other.brain);
	std::cout << "Cat has been assigned" << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "Grrrrr, miaaau" << std::endl;
}