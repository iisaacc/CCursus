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

const Animal *array[10];

for (int i = 0; i < 10; i++) {
	if (i < 5)
		array[i] = new Cat();
	else
		array[i] = new Dog();
}

for (int i = 0; i < 10; i++) {
	delete array[i];
}
return 0;
} //Shouldnt leak


