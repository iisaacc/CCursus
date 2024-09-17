#include "FragTrap.hpp"

FragTrap::FragTrap()//Solo es necesario llamar al constructor de ClapTrap en caso de que quieras llamar a uno que no sea el de por defecto, en caso contrario se hace automáticamente.
{
	set_Name("Default");
	set_Hit(100);
	set_Energy(100);
	set_Attack_Damage(30);
	std::cout << "FragTrap noname has been invoked" << std::endl;
}

FragTrap::FragTrap(std::string name)//Solo es necesario llamar al constructor de ClapTrap en caso de que quieras llamar a uno que no sea el de por defecto, en caso contrario se hace automáticamente.
{
	set_Name(name);
	set_Hit(100);
	set_Energy(100);
	set_Attack_Damage(30);
	std::cout << "FragTrap " << name << " has been invoked" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << get_Name() << " Destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	std::cout << "FragTrap Assignation operator called" << std::endl;
	this->set_Name(other.get_Name());
	this->set_Hit(other.get_Hit());
	this->set_Energy(other.get_Energy());
	this->set_Attack_Damage(other.get_Attack_Damage());
	return *this;

}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
	*this = copy;
}

void	FragTrap::attack(const std::string &target) {
	if (get_Energy() != 0 || get_Hit() != 0) {
	std::cout << "FragpTrap " << get_Name() << " attacks " << target << " causing " << get_Attack_Damage() << " points of damage!" << std::endl;
	set_Energy(get_Energy() - 1);
	}
	else if (get_Energy() == 0)
		std::cout << "FragTrap " << get_Name() << " has no energy" << std::endl;
	else
		std::cout << "FragTrap " << get_Name() << " has no hit points" << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount) {
	if (get_Energy() != 0 || get_Hit() != 0) {
		std::cout << "FragTrap " << get_Name() << " getting reapired by " << amount << " hit points" << std::endl;
		set_Hit(get_Hit() + amount);
		set_Energy(get_Energy() - 1);
	}
	else if (get_Energy() == 0)
		std::cout << "FragTrap " << get_Name() << " has no energy" << std::endl;
	else
		std::cout << "FragTrap " << get_Name() << " has no hit points" << std::endl;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << get_Name() << " high fives guys" << std::endl;
}
