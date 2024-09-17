#include "../Include/CommonInclude.hpp"

Ice::Ice() : AMateria("ice") {
}

Ice::Ice(Ice const &other) : AMateria(other), _type(other._type) {
	std::cout << "A Ice copy has appeared" << std::endl;
}

Ice::~Ice() {
	std::cout << "A Ice has been deleted" << std::endl;
}

Ice &Ice::operator=(Ice const &other) {
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria*	Ice::clone() const {
	return (new Ice);
}