#pragma once

#include <string>
#include <iostream>

class Animal {

	protected:
		std::string _type;
	
	public:
		Animal();
		Animal(std::string type);
		virtual ~Animal();
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);

		std::string		getType(void) const;
		void			setType(std::string type);
		virtual void	makeSound(void) const;

};