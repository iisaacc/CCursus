#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "A noname Dog has appeared" << std::endl;
}

Dog::Dog(std::string type) : Animal(type) {
	std::cout << "Dog with type " << type << " has appeared" << std::endl;
}

Dog::~Dog() {
}

void	Dog::makeSound(void) const {
	std::cout << "Dogs talk, and human are their best friend. Wasn't like that?" << std::endl;
}