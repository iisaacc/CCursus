#include "ClapTrap.hpp"

int main() {
	{
		ClapTrap a;
		ClapTrap b("Uan");

		a.attack("some other");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("some other other");
		b.beRepaired(3);
		for (int i = 0; i < 12; i++)
			b.attack("Uanillo");
		b.beRepaired(3);
	}
	return (0);




}