#pragma once

#include "CommonInclude.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice &other);
		~Ice();
		Ice&		operator=(const Ice &other);
		AMateria*	clone() const;
		void		use(ICharacter& target);
	private:
		std::string	_type;
};