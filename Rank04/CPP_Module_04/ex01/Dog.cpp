#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	this->brain = new Brain();
	std::cout << "A noname Dog has appeared" << std::endl;
}

Dog::Dog(std::string type) : Animal(type) {
	std::cout << "Dog with type " << type << " has appeared" << std::endl;
}

Dog::~Dog() {
	delete this->brain;
	std::cout << "Dog has been deleted" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	this->brain = new Brain(*other.brain);
	std::cout << "Dog has been copied" << std::endl;
}

Dog	&Dog::operator=(const Dog &other) {
	if (this == &other)
		return (*this);
	Animal::operator=(other);
	delete this->brain;
	this->brain = new Brain(*other.brain);
	std::cout << "Dog has been assigned" << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "Dogs talk, and human are their best friend. Wasn't like that?" << std::endl;
}

Brain	*Dog::getBrain(void) const {
	return (this->brain);
}