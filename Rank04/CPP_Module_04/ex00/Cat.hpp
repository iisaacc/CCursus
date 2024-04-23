#pragma once

#include "Animal.hpp"

class Cat: public Animal {
	public:
		Cat();
		Cat(std::string _type);
		~Cat();
		void	makeSound(void) const;
};