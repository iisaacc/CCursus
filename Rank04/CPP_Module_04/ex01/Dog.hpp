#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
	private:
		Brain *brain;

	public:
		Dog();
		Dog(std::string _type);
		~Dog();
		void	makeSound(void) const;
};