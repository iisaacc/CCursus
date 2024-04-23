#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {
	private:
		Brain *brain;

	public:
		Cat();
		Cat(std::string _type);
		~Cat();
		void	makeSound(void) const;
};