#include "../Include/CommonInclude.hpp"

Character::Character() : _name("") {
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	std::cout << "A noname Character Materia with type has appeared" << std::endl;
}

Character::Character(std::string name) : _name(name) {
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	std::cout << "A Character called " << name << " has appeared" << std::endl;
}

Character::Character(const Character &other) : _name(other._name) {
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	std::cout << "A Character copy called " << _name << " has appeared" << std::endl;
}

Character &Character::operator=(const Character &other) {
	if (this != &other)
	{
		_name = other._name;
	}
	return (*this);
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
	std::cout << "Character " << _name << " has been deleted" << std::endl;
}

std::string const &Character::getName() const {
	return(_name);
}

void	Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++)
	{
		if (i == 3 && this->_inventory[i] != NULL)
			std::cout << "The inventory is full" << std::endl;
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			std::cout << "The materia has been equiped at position " << i << std::endl;
			break;
		}
	}
}

void	Character::unequip(int idx) {
	if (idx > 3 || idx < 0)
		std::cout << "The slots go from 0 to 3 " << std::endl;
	else if (this->_inventory[idx] == NULL)
		std::cout << "There is no materia in the position " << idx << std::endl;
	else
		this->_inventory[idx] = NULL;
}


void	Character::use(int idx, ICharacter &target) {
	if (idx > 3 || idx < 0)
		std::cout << "The slots go from 0 to 3 " << std::endl;
	else if (this->_inventory[idx] == NULL)
		std::cout << "There is no materia in the position " << idx << std::endl;
	else
		this->_inventory[idx]->use(target);
}

