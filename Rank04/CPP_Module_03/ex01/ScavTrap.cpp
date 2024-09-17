#include "ScavTrap.hpp"

ScavTrap::ScavTrap()//Solo es necesario llamar al constructor de ClapTrap en caso de que quieras llamar a uno que no sea el de por defecto, en caso contrario se hace automáticamente.
{
	set_Name("Default");
	set_Hit(100);
	set_Energy(50);
	set_Attack_Damage(20);
	this->_guarding_gate = false;
	std::cout << "Scavtrap noname has been invoked" << std::endl;
}

ScavTrap::ScavTrap(std::string name)//Solo es necesario llamar al constructor de ClapTrap en caso de que quieras llamar a uno que no sea el de por defecto, en caso contrario se hace automáticamente.
{
	set_Name(name);
	set_Hit(100);
	set_Energy(50);
	set_Attack_Damage(20);
	this->_guarding_gate = false;
	std::cout << "Scavtrap " << name << " has been invoked" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << get_Name() << " Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	this->set_Name(other.get_Name());
	this->set_Hit(other.get_Hit());
	this->set_Energy(other.get_Energy());
	this->set_Attack_Damage(other.get_Attack_Damage());
	return *this;

}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
	*this = copy;
}

void	ScavTrap::attack(const std::string &target) {
	if (get_Energy() != 0 || get_Hit() != 0) {
	std::cout << "ScavpTrap " << get_Name() << " attacks " << target << " causing " << get_Attack_Damage() << " points of damage!" << std::endl;
	set_Energy(get_Energy() - 1);
	}
	else if (get_Energy() == 0)
		std::cout << "ScavTrap " << get_Name() << " has no energy" << std::endl;
	else
		std::cout << "ScavTrap " << get_Name() << " has no hit points" << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount) {
	if (get_Energy() != 0 || get_Hit() != 0) {
		std::cout << "ScavTrap " << get_Name() << " getting reapired by " << amount << " hit points" << std::endl;
		set_Hit(get_Hit() + amount);
		set_Energy(get_Energy() - 1);
	}
	else if (get_Energy() == 0)
		std::cout << "ScavTrap " << get_Name() << " has no energy" << std::endl;
	else
		std::cout << "ScavTrap " << get_Name() << " has no hit points" << std::endl;
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << get_Name() << " is now in keeper mode" << std::endl;
	this->_guarding_gate = true;
}