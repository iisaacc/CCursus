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

// Si tienes un objeto pequeño que solo necesitas dentro de un ámbito limitado, es útil almacenarlo en el stack.
// Si tienes un objeto que necesita persistir más allá de un solo ámbito, o si el objeto es muy grande, es útil almacenarlo en el heap.