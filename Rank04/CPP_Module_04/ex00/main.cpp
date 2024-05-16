#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "---------Normal animal tests----------" << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Cat();// El hecho de que j sea un puntero a Animal en lugar de un puntero a Dog significa que solo puedes usar j para llamar a métodos que están declarados en Animal (o en las clases base de Animal). Sin embargo, si estos métodos son virtuales y están sobrescritos en Dog, entonces se llamará a la versión Dog de los métodos.
	const Animal* i = new Dog();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound(); //will output the cat sound!
	meta->makeSound();

	std::cout << "---------Wrong animal tests----------" << std::endl;

	const WrongAnimal*	Wmeta = new WrongAnimal();
	const WrongAnimal*	j = new WrongCat();
	WrongCat			*i = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound(); //will output the cat sound!
	meta->makeSound();
	return 0;
}
