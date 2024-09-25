#include "Harl.hpp"

int	ft_harl_select(char *argv)
{
	std::string	options[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if (options[i] == argv)
			return (i);
	}
	return (-1);
}

void	ft_harl_switch(char *argv, Harl Harl)
{
	switch (ft_harl_select(argv))
	{
	case 0:
		Harl.complain("DEBUG");
	case 1:
		Harl.complain("INFO");
	case 2:
		Harl.complain("WARNING");
	case 3:
		Harl.complain("ERROR");
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}

int main(int argc, char *argv[])
{
	Harl	Harl;

	if (argc != 2) {
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	} else
		ft_harl_switch(argv[1], Harl);
	return (0);
}