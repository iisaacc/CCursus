#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat") {
	std::cout << "A noname WrongCat appeared" << std::endl;
}

WrongCat::WrongCat(std::string const &type): WrongAnimal(type) {
	std::cout << "A noname WrongCat appeared" << std::endl;
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat has been deleted" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal(other) {
	std::cout << "WrongCat has been copied" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

void	WrongCat::makeSound(void) const {
	std::cout << "MiAAooo WrongCat" << std::endl;
}