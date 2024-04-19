#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	private:
		bool _guarding_gate;

	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &copy);
		virtual ~ScavTrap();

		ScavTrap &operator=(const ScavTrap &src);

		void	guardGate();
		void	attack(const std::string &target);
		void	beRepaired(unsigned int amount);
};

#endif