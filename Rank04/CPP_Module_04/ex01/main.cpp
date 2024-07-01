#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

// En este ejercicio Cat y Dog contienen punteros a un objeto brain, por lo que si hacemos una
// copia shallow (superficial), haremos una copia bit a bit y copiaremos el puntero a brain
// entre las copias. Por lo que deberíamos implementar una copia profunda en el constructor de copia
// y en el de asignación.

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	const Animal *array[4];

	for (int i = 0; i < 4; i++) {
		if (i < 2)
			array[i] = new Cat();
		else
			array[i] = new Dog();
	}

	for (int i = 0; i < 4; i++) {
		delete array[i];
	}

	std::cout << "---------Brain deep copy tests tests----------" << std::endl;
	Dog basic;
	Dog tmp = basic;
	std::cout << basic.getBrain() << std::endl;
	std::cout << tmp.getBrain() << std::endl;

	return 0;
} //Shouldnt leak


