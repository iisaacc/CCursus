#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("noname"), _hit(10), _attack_dmg(0), _energy(10) {
	std::cout << "A no name Claptrap has been invoked" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit(10), _attack_dmg(0), _energy(10) {
	std::cout << "Claptrap " << name << " has been invoked" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "ClapTrap Assignation operator called" << std::endl;
	this->_attack_dmg = other._attack_dmg;
	this->_hit = other._hit;
	this->_name = other._name;
	this->_energy = other._energy;
	return *this;
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << _name << " disapeared" << std::endl;
}

void	ClapTrap::set_Energy(int energy) {
	std::cout << "ClapTrap " << _name << "setting energy points to " << energy << std::endl;
	this->_energy = energy;
}

void	ClapTrap::set_Attack_Damage(int attack_dmg) {
	std::cout << "ClapTrap " << _name << "setting Attack damage to " << attack_dmg << std::endl;
	this->_attack_dmg = attack_dmg;
}

void	ClapTrap::set_Hit(int hit) {
	std::cout << "ClapTrap " << _name << "setting Hitting points to " << hit << std::endl;
	this->_hit = hit;
}

int	ClapTrap::get_Attack_Damage() {
	return (this->_attack_dmg);
}

int	ClapTrap::get_Hit() {
	return (this->_hit);
}

int	ClapTrap::get_Energy() {
	return (this->_energy);
}

void	ClapTrap::attack(const std::string& target) {
	if (this->_energy != 0 || this->_hit != 0) {
	std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attack_dmg << " points of damage!" << std::endl;
	this->_energy--;
	}
	else if (this->_energy == 0)
		std::cout << "ClapTrap " << _name << " has no energy" << std::endl;
	else
		std::cout << "ClapTrap " << _name << " has no hit points" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	this->_hit -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energy != 0 || this->_hit != 0) {
		std::cout << "ClapTrap " << _name << " getting reapired by " << amount << " hit points" << std::endl;
		this->_hit += amount;
		this->_energy--;
	}
	else if (this->_energy == 0)
		std::cout << "ClapTrap " << _name << " has no energy" << std::endl;
	else
		std::cout << "ClapTrap " << _name << " has no hit points" << std::endl;
}