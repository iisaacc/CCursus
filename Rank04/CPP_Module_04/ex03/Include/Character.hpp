#pragma once

#include "CommonInclude.hpp"

class Character: public ICharacter {

	private:
		std::string	_name;
		AMateria	*_inventory[4]; //Usamos un puntero para que podamos almacenar todo tipo de materias

	public:
		Character();
		Character(std::string name);
		Character(const Character &other);
		Character &operator=(const Character &other);
		~Character();

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};