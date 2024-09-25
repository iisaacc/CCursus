#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>
#include <sstream>

class ClapTrap {

private:

	std::string	_name;
	int			_hit;			//Hit points
	int			_attack_dmg;	//Attact damage
	int			_energy;		//Energy points

public:

//--------------------CONST & DESTR---------------------

	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &copy);
	ClapTrap &operator=(const ClapTrap &other);
	~ClapTrap(void);

	//virtual void	printConst(std::string	message) const;
	//virtual void	printDest(std::string	message) const;
	//virtual void	printSet(std::string	message) const;

//------------------GETTERS & SETTERS-------------------

	void		set_Name(std::string name);
	void		set_Energy(int energy);
	void		set_Attack_Damage(int attack_dmg);
	void		set_Hit(int hit);

	std::string	get_Name() const;
	int			get_Hit() const;
	int			get_Attack_Damage() const;
	int			get_Energy() const;

//------------------METHODS----------------------------
	virtual	void	attack(const std::string& target);
	virtual	void	beRepaired(unsigned int amount);
	void			takeDamage(unsigned int amount);
};

#endif