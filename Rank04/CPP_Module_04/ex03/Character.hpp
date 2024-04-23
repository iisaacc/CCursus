#pragma once

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class Character: public ICharacter {

	private:
		Materia *_inventory[4];

	public:
		Character();
		~Character();
		std::string	const & getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};