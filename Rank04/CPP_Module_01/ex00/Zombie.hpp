#ifndef ZOMBIE_HPP

# define ZOMBIE_HPP
# include <string>
# include <iostream>

class Zombie {
	public:
	
		~Zombie(void);
		Zombie(std::string name);
		Zombie(void);

		static Zombie*	newZombie(std::string name);
		static void	randomChump( std::string name );
		void	announce(void);

	private:

		std::string	_name;
};

#endif