#pragma once

#include "Animal.hpp"

class Dog: public Animal {
	public:
		Dog();
		Dog(std::string _type);
		~Dog();
		Dog(const Dog &other);
		Dog	&operator=(const Dog &other);
		void	makeSound(void) const;
};