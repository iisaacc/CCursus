#include "../Include/CommonInclude.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		this->_materias[i] = NULL;
	}
	std::cout << "A Materia Source has been created" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &other) {
	for (int i = 0; i < 4; i++) {
		this->_materias[i] = NULL;
	}
	for (int i = 0; i < 4; i++)
	{
		if (other._materias[i] != NULL)
			this->_materias[i] = other._materias[i]->clone();
		else
			this->_materias[i] = NULL;
	}
	std::cout << "A Materia Source copy has been created" << std::endl;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] != NULL)
			delete this->_materias[i];
	}
	std::cout << "A MateriaSource has been deleted" << std::endl;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other) {
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_materias[i] != NULL)
				delete this->_materias[i];
			if (other._materias[i] != NULL)
				this->_materias[i] = other._materias[i]->clone();
			else
				this->_materias[i] = NULL;
		}
	}
	std::cout << "A Materia Source assignation operator has been used" << std::endl;
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* lmateria) {
	for (int i = 0; i < 4; i++)
	{
		if (i == 3 && this->_materias[i] != NULL)
			std::cout << "You can't learn more materias, slots are full" << std::endl;
		if (this->_materias[i] == NULL)
		{
			this->_materias[i] = lmateria;
			std::cout << "You have learned a new materia of type " << lmateria->getType() << std::endl;
			break;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] != NULL && this->_materias[i]->getType() == type)
			return (this->_materias[i]->clone());
	}
	std::cout << "You haven' learned yet a materia of type " << type << std::endl;
	return (NULL);
}
