#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>
#include <sstream>

class ClapTrap {

private:

	std::string	_name;
	int			_hit;			//Hit points
	int			_energy;		//Energy points
	int			_attack_dmg;	//Attact damage

public:

//--------------------CONST & DESTR---------------------

	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &copy);
	ClapTrap &operator=(const ClapTrap &other);
	~ClapTrap(void);

//------------------GETTERS & SETTERS-------------------

	void	set_Energy(int energy);
	void	set_Attack_Damage(int attack_dmg);
	void	set_Hit(int hit);

	int		get_Hit();
	int		get_Attack_Damage();
	int		get_Energy();

//------------------METHODS----------------------------
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif