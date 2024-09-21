#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <stack>
#include <cctype>
#include <stdexcept>

class RPN {
	private:
		std::stack<int>	_values;

	public:
		RPN();
		~RPN();
		RPN(std::string input);
		RPN(RPN &other);
		RPN	&operator=(RPN &other);
		int	operate(int n1, int n2, char c);
		bool	is_operator(char c);
};