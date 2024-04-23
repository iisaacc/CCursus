#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	this->brain = new Brain();
	std::cout << "A noname Cat has appeared" << std::endl;
}

Cat::Cat(std::string type) : Animal(type) {
	std::cout << "Cat with type " << type << " has appeared" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat has been deleted" << std::endl;
	delete this->brain;
}

void	Cat::makeSound(void) const {
	std::cout << "Grrrrr, miaaau" << std::endl;
}