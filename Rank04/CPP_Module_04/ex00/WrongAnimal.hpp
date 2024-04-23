#pragma once

#include <string>
#include <iostream>

class WrongAnimal
{
	private:
		std::string _type;

	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal &operator=(const WrongAnimal &other);
		std::string		getType(void) const;
		void			setType(std::string type);

		void	makeSound(void) const;
};

