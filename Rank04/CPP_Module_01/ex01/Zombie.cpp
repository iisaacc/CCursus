#include "Zombie.hpp"

//Constructores y destructores
Zombie::Zombie() : _name("") {
}
Zombie::Zombie(std::string name) {
	_name = name;
}
Zombie::~Zombie() {
	std::cout << _name << " ha desaparecido." << std::endl;
}
Zombie	*Zombie::newZombie(std::string name) {
	Zombie *newZombie = new Zombie(name);
	return (newZombie);
}

//Setters
void	Zombie::setName(std::string name) {
	this->_name = name;
}

//Métodos

void	Zombie::announce (void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}