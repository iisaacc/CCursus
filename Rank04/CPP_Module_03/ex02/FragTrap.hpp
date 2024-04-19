#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &copy);
		virtual ~FragTrap();

		FragTrap &operator=(const FragTrap &src);

		void	highFivesGuys(void);
		void	attack(const std::string &target);
		void	beRepaired(unsigned int amount);
};

#endif