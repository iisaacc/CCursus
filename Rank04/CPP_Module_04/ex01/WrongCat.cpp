#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat") {
	std::cout << "A noname WrongCat appeared" << std::endl;
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat has been deleted" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal(other) {
	std::cout << "WrongCat has been copied" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &other) {
	if (this == &other)
		return (*this);
	WrongAnimal::operator=(other);
	std::cout << "WrongCat has been assigned" << std::endl;
	return (*this);
}

void	WrongCat::makeSound(void) const {
	std::cout << "MiAAooo WrongCat" << std::endl;
}