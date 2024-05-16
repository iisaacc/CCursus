#pragma once

#include "Animal.hpp"

class Cat: public Animal {
	public:
		Cat();
		Cat(std::string _type);
		~Cat();
		Cat(const Cat &other);
		Cat	&operator=(const Cat &other);
		void	makeSound(void) const;
};