#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2) {
		std::cerr << "Usage: ./PmergeMe [n1] [n2]..." << std::endl;
		return (1);
	}
	PmergeMe(argv, argc);
	return (0);
}