#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon {
	public:
		//Construct & Destruct
		Weapon();
		Weapon(std::string type);
		~Weapon();
		//Setters
		void				setType(std::string type);

		//Getters
		const std::string&	getType(void);


	private:
		std::string	_type;

};

#endif