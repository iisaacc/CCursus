#pragma once

#include "CommonInclude.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_materias[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		~MateriaSource();
		MateriaSource	&operator=(const MateriaSource &other);

		void		learnMateria(AMateria* lmateria);
		AMateria*	createMateria(std::string const & type);

};