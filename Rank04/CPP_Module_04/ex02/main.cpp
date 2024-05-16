#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	//const Animal* meta = new Animal();//No se puede instanciar un objeto de una clase abstracta
	const Animal* j = new Cat();// El hecho de que j sea un puntero a Animal en lugar de un puntero a Dog significa que solo puedes usar j para llamar a métodos que están declarados en Animal (o en las clases base de Animal). Sin embargo, si estos métodos son virtuales y están sobrescritos en Dog, entonces se llamará a la versión Dog de los métodos.
	const Animal* i = new Dog();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();

	delete j;//Se llama al destructor de Cat
	delete i;//Se llama al destructor de Dog
	return 0;
}
