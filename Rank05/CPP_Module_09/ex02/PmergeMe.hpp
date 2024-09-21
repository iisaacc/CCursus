#pragma once

#include <string>
#include <deque>
#include <vector>
#include <cstdlib>

class PmergeMe {

	private:
		std::vector<unsigned int>	_vector;
		std::deque<unsigned int>	_deque;
	public:
		PmergeMe();
		PmergeMe(char **input, int argc);
		PmergeMe(PmergeMe &other);
		~PmergeMe();
		PmergeMe &operator=(PmergeMe &other);
};