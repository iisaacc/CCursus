#include "FragTrap.hpp"

void	paco_rundown(void)
{
	FragTrap paco("paco");

	paco.attack("Uan");
	paco.attack("Chris");
	paco.attack("Diana");
	paco.attack("Elisa");
	paco.attack("Fred");
	paco.attack("Gemma");
	paco.attack("Henry");
	paco.attack("Isabella");
	paco.attack("Jack");
	paco.attack("Kevin");
	paco.attack("Laura");
	paco.attack("Mike");
	paco.highFivesGuys();
}

void	Uan_rundown(void)
{
	FragTrap	Uan("Uan");

	while (Uan.get_Hit())
	{
		Uan.takeDamage(20);
		Uan.beRepaired(10);
	}
	Uan.takeDamage(1);
	Uan.highFivesGuys();
}

int	main(void)
{
	std::cout << std::endl << std::endl << "Performing Paco's tests..." << std::endl << std::endl;
	paco_rundown();
	std::cout << std::endl << std::endl << "Performing Uan's tests..." << std::endl << std::endl;
	Uan_rundown();
}