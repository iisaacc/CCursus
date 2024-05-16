#pragma once

#include "CommonInclude.hpp"

class Cure : public AMateria
{
	private:
		std::string	_type;

	public:
		Cure();
		Cure(const Cure &other);
		~Cure();
		Cure&		operator=(const Cure &other);
		AMateria*	clone() const;
		void		use(ICharacter& target);
};