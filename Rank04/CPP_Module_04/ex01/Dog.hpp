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
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		void	makeSound(void) const;
		Brain	*getBrain(void) const;
};