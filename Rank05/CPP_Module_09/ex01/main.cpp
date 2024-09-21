#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: ./program [input]" << std::endl;
		return (1);
	}
	else {
		try{
			RPN rpn(argv[1]);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			return (1);
		}
	}
}