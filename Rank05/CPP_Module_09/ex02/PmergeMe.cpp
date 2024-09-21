#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **input, int argc) {
	for (int i; i < argc; ++i) {
		_vector.push_back(std::atoi(input[i]));
		_deque.push_back(std::atoi(input[i]));
	}
	
}

PmergeMe::PmergeMe(PmergeMe &other) {
	this->_vector = other._vector;
	this->_deque = other._deque;
}

PmergeMe::~PmergeMe() {}
