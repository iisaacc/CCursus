#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(/* args */);
		~WrongCat();
		void	makeSound(void) const;
};

