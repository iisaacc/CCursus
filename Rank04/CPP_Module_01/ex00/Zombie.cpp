#include "Zombie.hpp"

Zombie::Zombie() : _name("") {
}
Zombie::Zombie(std::string name) {
	_name = name;
}
Zombie::~Zombie() {
	std::cout << _name << " ha desaparecido" << std::endl;
}

void	Zombie::announce (void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}