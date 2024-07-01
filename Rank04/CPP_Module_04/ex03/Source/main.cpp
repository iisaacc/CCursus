#include "../Include/CommonInclude.hpp"

void	ft_clean_Materias(AMateria *allMaterias[], int count)
{
	for (int i = 0; i < count; i++)
	{
		delete allMaterias[i];
		allMaterias[i] = NULL;
	}
}

int main()
{
	AMateria	*allMaterias[20];
	int			count = 0;

	std::cout << "---------CREATING----------" << std::endl << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	allMaterias[count++] = tmp;
	std::cout << std::endl <<"---------EQUIPPING & USING----------" << std::endl << std::endl;
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->unequip(0);
	me->use(0, *bob);
	ft_clean_Materias(allMaterias, count);
	delete bob;
	delete me;
	delete src;
	return 0;
}