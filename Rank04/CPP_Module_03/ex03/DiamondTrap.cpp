#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()//Solo es necesario llamar al constructor de ClapTrap en caso de que quieras llamar a uno que no sea el de por defecto, en caso contrario se hace automáticamente.
{
	set_Name("Default");
	set_Hit(100);
	set_Energy(50);
	set_Attack_Damage(30);
	std::cout << "DiamondTrap noname has been invoked" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) :  ScavTrap(name), FragTrap(name), _name(name + "_clap_name")//Solo es necesario llamar al constructor de ClapTrap en caso de que quieras llamar a uno que no sea el de por defecto, en caso contrario se hace automáticamente.
{
	set_Hit(100);
	set_Energy(50);
	set_Attack_Damage(30);
	std::cout << "DiamondTrap " << name << " has been invoked" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->_name << " Destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	std::cout << "DiamondTrap Assignation operator called" << std::endl;
	this->ScavTrap::set_Name(other.ScavTrap::get_Name());
	this->ScavTrap::set_Hit(other.ScavTrap::get_Hit());
	this->ScavTrap::set_Energy(other.ScavTrap::get_Energy());
	this->ScavTrap::set_Attack_Damage(other.ScavTrap::get_Attack_Damage());
	return *this;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) :  ClapTrap(copy), ScavTrap(copy), FragTrap(copy) {
	*this = copy;
}

void	DiamondTrap::beRepaired(unsigned int amount) {
	if (get_Energy() != 0 || get_Hit() != 0) {
		std::cout << "DiamondTrap " << get_Name() << " getting reapired by " << amount << " hit points" << std::endl;
		set_Hit(get_Hit() + amount);
		set_Energy(get_Energy() - 1);
	}
	else if (get_Energy() == 0)
		std::cout << "DiamondTrap " << get_Name() << " has no energy" << std::endl;
	else
		std::cout << "DiamondTrap " << get_Name() << " has no hit points" << std::endl;
}

void	DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::WhoAmI() {
	std::cout << "I am DiamondTrap " << get_Name() << " and my ClapTrap name is "<< _name << std::endl;
}
