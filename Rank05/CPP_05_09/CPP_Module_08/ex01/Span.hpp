#pragma once

#include <algorithm>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <limits>
#include <cstdlib>
#include <ctime>

class Span {
	public:
		Span();
		Span(unsigned int N);
		~Span();
		Span(const Span &other);
		Span 	&operator=(const Span &other);
		void	addNumber(int number);
		int		shortestSpan();
		int		longestSpan();
		void	randomFillVector(int N);
		void 	printVector();
		class ReachedMaxSizeException : public std::exception {
			public:
				virtual const char *what()const throw();
		};
		class NotEnoughNumbersException : public std::exception {
			public:
				virtual const char *what()const throw();
		};

	private:
		unsigned int		_N;
		std::vector<int>	_vec;
};