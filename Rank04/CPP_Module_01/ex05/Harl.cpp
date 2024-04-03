#include "Harl.hpp"

Harl::Harl(void){
	std::cout << "Ey you my name is Harl" << std::endl;
}
Harl::~Harl(void){
	std::cout << "Noss bemo" << std::endl;
}

void	Harl::debug(){
	std::cout << "Yes yes how I was saying I like football, but just watching It. Get out of my way!" << std::endl << std::endl;
}

void	Harl::info(){
	std::cout << "WTF Your are in front of my TV so I cant see this interesting game (Yugoslavia vs Romania), Im not moving, so you know!" << std::endl << std::endl;
}

void	Harl::warning(){
	std::cout << "Really?! Your are already in front of my TV and Im even getting hungry, so do your calculations and bring me food 2x1!" << std::endl << std::endl;
}

void	Harl::error(){
	std::cout << "OMG! I hate dealing with people like this. I will have to take action on the matter, Im gonna sleep. Bye." << std::endl << std::endl;
}

void	Harl::complain(std::string level) {
	void		(Harl::*ptr_complain[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*ptr_complain[i])();
			break;
		}
	}
}