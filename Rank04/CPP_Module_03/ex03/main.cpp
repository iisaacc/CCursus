#include "DiamondTrap.hpp"

void	paco_rundown(void)
{
	DiamondTrap paco("paco");

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
	paco.WhoAmI();
}

void	Uan_rundown(void)
{
	DiamondTrap	Uan("Uan");

	while (Uan.get_Hit())
	{
		Uan.takeDamage(20);
	}
	Uan.takeDamage(1);
}

int	main(void)
{
	std::cout << std::endl << std::endl << "Performing Paco's tests..." << std::endl << std::endl;
	paco_rundown();
	std::cout << std::endl << std::endl << "Performing Uan's tests..." << std::endl << std::endl;
	Uan_rundown();
}