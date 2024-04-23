#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	this->brain = new Brain();
	std::cout << "A noname Dog has appeared" << std::endl;
}

Dog::Dog(std::string type) : Animal(type) {
	std::cout << "Dog with type " << type << " has appeared" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog has been deleted" << std::endl;
	delete this->brain;
}

void	Dog::makeSound(void) const {
	std::cout << "Dogs talk, and human are their best friend. Wasn't like that?" << std::endl;
}