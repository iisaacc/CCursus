#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "A noname Cat has appeared" << std::endl;
}

Cat::Cat(std::string type) : Animal(type) {
	std::cout << "Cat with type " << type << " has appeared" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat has been deleted" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other._type){
	*this = other;
}

Cat	&Cat::operator=(const Cat &other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "Grrrrr, miaaau" << std::endl;
}