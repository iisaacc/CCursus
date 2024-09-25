#include "../Include/CommonInclude.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {
	std::cout << "An Abstract Materia with type " << type << " has appeared" << std::endl;
}

AMateria::AMateria(AMateria const &other) : _type(other._type) {
	std::cout << "An Abstract Materia copy with type " << _type << " has appeared" << std::endl;
}

AMateria &AMateria::operator=(AMateria const &other) {
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

AMateria::~AMateria() {
	std::cout << "AMateria with type " << _type << " has been deleted" << std::endl;
}

std::string const &AMateria::getType() const {
	return (_type);
}

void AMateria::use(ICharacter &target) {
	std::cout << "AMateria do something abstract on " << target.getName() << std::endl;
}