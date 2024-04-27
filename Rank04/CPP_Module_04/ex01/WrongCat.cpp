#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "A noname WrongCat has appeared" << std::endl;
}

WrongCat::~WrongCat(){
	std::cout << "A WrongCat has been destroyed" << std::endl;
}

void	WrongCat::makeSound(void) const {
	std::cout << "WrongCat sound" << std::endl;
}