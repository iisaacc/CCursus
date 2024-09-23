#include "PmergeMe.hpp"

std::deque<unsigned int>	PmergeMe::mergeDeq(std::deque<unsigned int> deq1, std::deque<unsigned int> deq2) {
	std::deque<unsigned int>			result;
	std::deque<unsigned int>::iterator	it1 = deq1.begin();
	std::deque<unsigned int>::iterator	it2 = deq2.begin();

	while (it1 != deq1.end() && it2 != deq2.end()) {
		if (*it1 < *it2)
			result.push_back(*it1++);
		else
			result.push_back(*it2++);
	}

	if (it1 != deq1.end())
		result.insert(result.end(), it1, deq1.end());
	if (it2 != deq2.end())
		result.insert(result.end(), it2, deq2.end());

	return (result);
}

std::vector<unsigned int>	PmergeMe::mergeVec(std::vector<unsigned int> vec1, std::vector<unsigned int> vec2) {
	std::vector<unsigned int>			result;
	std::vector<unsigned int>::iterator	it1 = vec1.begin();
	std::vector<unsigned int>::iterator	it2 = vec2.begin();

	while (it1 != vec1.end() && it2 != vec2.end()) {
		if (*it1 < *it2)
			result.push_back(*it1++);
		else
			result.push_back(*it2++);
	}

	if (it1 != vec1.end())
		result.insert(result.end(), it1, vec1.end());
	if (it2 != vec2.end())
		result.insert(result.end(), it2, vec2.end());

	return (result);
}

std::deque<unsigned int>	PmergeMe::fordJohnsonDeq(std::deque<unsigned int> original) {
	std::deque<unsigned int>	smaller;
	std::deque<unsigned int>	larger;

	size_t	i = 0;

	// Divide the original stack in 2 comparing pairs and choosing the smaller and larger
	while (i + 1 < original.size())
	{
		if (original[i] < original[i + 1]) {
			smaller.push_back(original[i]);
			larger.push_back(original[i + 1]);
		}
		else {
			larger.push_back(original[i]);
			smaller.push_back(original[i + 1]);
		}
		i += 2;
	}

	 if (original.size() % 2 != 0) {
		smaller.push_back(original.back());
	}

	if (smaller.size() > 1)
		smaller = fordJohnsonDeq(smaller);
	if (larger.size() > 1)
		larger = fordJohnsonDeq(larger);
	
	return (mergeDeq(smaller, larger));
}

std::vector<unsigned int>	PmergeMe::fordJohnsonVec(std::vector<unsigned int> original) {
	std::vector<unsigned int>	smaller;
	std::vector<unsigned int>	larger;

	size_t	i = 0;

	// Divide the original stack in 2 comparing pairs and choosing the smaller and larger
	while (i + 1 < original.size())
	{
		if (original[i] < original[i + 1]) {
			smaller.push_back(original[i]);
			larger.push_back(original[i + 1]);
		}
		else {
			larger.push_back(original[i]);
			smaller.push_back(original[i + 1]);
		}
		i += 2;
	}

	 if (original.size() % 2 != 0) {
		smaller.push_back(original.back());
	}

	if (smaller.size() > 1)
		smaller = fordJohnsonVec(smaller);
	if (larger.size() > 1)
		larger = fordJohnsonVec(larger);
	
	return (mergeVec(smaller, larger));
}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **input, int argc) {
	for (int i = 0; i < argc; ++i) {
		_vector.push_back(std::atoi(input[i]));
		_deque.push_back(std::atoi(input[i]));
	}

	std::cout << "Before: ";
	printContainer(_vector);
	std::clock_t	start = std::clock();
	_deque = fordJohnsonDeq(_deque);
	std::clock_t	end = std::clock();
	double	duration = 1000.0 * (end - start) / CLOCKS_PER_SEC;
	std::cout << "After: ";
	printContainer(_deque);
	std::cout << "Time to proceed a range of " << argc - 1 << " with std::deque : " << duration << "." << std::endl;
	start = std::clock();
	_vector = fordJohnsonVec(_vector);
	end = std::clock();
	duration = 1000.0 * (end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to proceed a range of " << argc - 1 << " with std::vector : " << duration << "." << std::endl;
}

PmergeMe::PmergeMe(PmergeMe &other) {
	this->_vector = other._vector;
	this->_deque = other._deque;
}

PmergeMe	&PmergeMe::operator=(PmergeMe &other) {
	if (this != &other) {
		this->_deque = other._deque;
		this->_vector = other._vector;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}
