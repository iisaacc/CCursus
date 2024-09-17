#include "Zombie.hpp"

int main()
{
	int N = 10;
	Zombie *horde = Zombie::zombieHorde(N, "maiki");

	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}
	delete[] horde;
}