#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include "Weapon.hpp"

class HumanB {

	public:
		//Construct & destruct
		HumanB(std::string name);
		~HumanB();

		//Setters
		void	setWeapon(Weapon &weapon);

		//Métodos
		void	attack(void);
		
	private:
		std::string	_name;
		Weapon		*_weapon;
};

#endif