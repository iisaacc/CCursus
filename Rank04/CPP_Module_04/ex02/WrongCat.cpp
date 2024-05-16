#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
	std::cout << "A noname WrongCat has appeared" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat " << this->getType() << " has disappeared" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) {
	*this = other;
}

WrongCat	&WrongCat::operator=(const WrongCat &other) {
	this->setType(other.getType());
	return (*this);
}

void	WrongCat::makeSound(void) const {
	std::cout << "WrongCat sound" << std::endl;
}