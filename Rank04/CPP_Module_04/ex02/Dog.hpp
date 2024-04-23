#pragma once

#include "Animal.hpp"

class Dog: public Animal {
	public:
		Dog();
		Dog(std::string _type);
		~Dog();
		void	makeSound(void) const;
};