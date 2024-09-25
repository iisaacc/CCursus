#include "../Include/CommonInclude.hpp"

Cure::Cure() : AMateria("cure") {
}

Cure::Cure(Cure const &other) : AMateria(other), _type(other._type) {
	std::cout << "A Cure copy has appeared" << std::endl;
}

Cure::~Cure() {
	std::cout << "A Cure has been deleted" << std::endl;
}

Cure &Cure::operator=(Cure const &other) {
	if (this != &other)
		this->_type = other._type;
	return (*this);
}


void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

AMateria*	Cure::clone() const {
	return (new Cure);
}