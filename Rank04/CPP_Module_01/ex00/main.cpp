#include "Zombie.hpp"

int main()
{
	Zombie stack("Juan");
	Zombie *heap = Zombie::newZombie("Torrao");
	
	stack.announce();
	heap->announce();
	Zombie::randomChump("uanfran");
	delete heap;
}