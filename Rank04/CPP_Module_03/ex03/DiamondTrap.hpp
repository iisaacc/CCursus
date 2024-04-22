#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {

	private:
		std::string	_name;

	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &copy);
		virtual ~DiamondTrap();

		DiamondTrap &operator=(const DiamondTrap &src);

		void	beRepaired(unsigned int amount);
		void			attack(const std::string &target);
		void			WhoAmI();
};