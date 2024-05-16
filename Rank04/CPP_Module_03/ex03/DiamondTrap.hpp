#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

// La herencia virtual soluciona el problema de ambigüedad al asegurar
// que sólo haya una copia de los miembros de la clase base en la clase derivada,
// incluso si la clase base es heredada más de una vez indirectamente.
// De forma que sólo hay una copia de los miembros de Base(ClapTrap) en Diamond.

class DiamondTrap: public ScavTrap, public FragTrap {

	private:
		std::string	_name;

	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &copy);
		virtual	~DiamondTrap();

		DiamondTrap &operator=(const DiamondTrap &src);

		void	beRepaired(unsigned int amount);
		void	attack(const std::string &target);
		void	WhoAmI();
};