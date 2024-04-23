#pragma once

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		//[...]
	public:
		AMateria(std::string const & type);
		//[...]
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
