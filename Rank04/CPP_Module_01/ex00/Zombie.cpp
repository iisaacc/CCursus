#include "Zombie.hpp"

Zombie::Zombie() : _name("") {
}
Zombie::Zombie(std::string name) {
	_name = name;
}
Zombie::~Zombie() {
	std::cout << _name << std::endl;
}

Zombie	*Zombie::newZombie(std::string name) {
	Zombie *newZombie = new Zombie(name);
	return (newZombie);
}

void	Zombie::announce (void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}