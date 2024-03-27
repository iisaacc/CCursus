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
		static void		randomChump(std::string name);
		static Zombie*	zombieHorde(int N, std::string name);
		void			announce(void);

	private:

		void	setName(std::string name);

		std::string	_name;
};

#endif