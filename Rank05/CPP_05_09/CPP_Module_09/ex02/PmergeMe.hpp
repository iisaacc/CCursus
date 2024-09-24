#pragma once

#include <string>
#include <deque>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <ctime>

template < typename T >
void	printContainer(T container)
{
	for (size_t i = 0; i < container.size(); ++i)
		std::cout << container[i] << " ";

	std::cout << std::endl;
}

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
		std::deque<unsigned int>	fordJohnsonDeq(std::deque<unsigned int> original);
		std::vector<unsigned int>	fordJohnsonVec(std::vector<unsigned int> original);
		std::deque<unsigned int>	mergeDeq(std::deque<unsigned int> deq1, std::deque<unsigned int> deq2);
		std::vector<unsigned int>	mergeVec(std::vector<unsigned int> vec1, std::vector<unsigned int> vec2);
};
