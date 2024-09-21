#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(RPN &other) {
	this->_values = other._values;
}

RPN	&RPN::operator=(RPN &other) {
	if (this != &other)
		this->_values = other._values;
	return (*this);
}

bool	RPN::is_operator(char c)
{
	return (c == '-' || c == '/' || c == '+' || c == '*');
}

int	RPN::operate(int n1, int n2, char c)
{
	if (c == '+')	
		return (n1 + n2);
	else if (c == '-')	
		return (n1 - n2);
	else if (c == '*')	
		return (n1 * n2);
	else
		return (n1 / n2);
}

RPN::RPN(std::string input) {
	int	first;
	int second;

	for (size_t i = 0; i < input.length(); ++i) {
		if (isdigit(input[i])) {
			_values.push(input[i] - '0');
		}
		else if (is_operator(input[i]) && _values.size() > 1) {
			second = _values.top();
			_values.pop();
			first = _values.top();
			_values.pop();
			//std::cout << "Operation: " << first << " " << input[i] << " " << second << std::endl;
			_values.push(operate(first, second, input[i]));
		}
		else if (is_operator(input[i]) && _values.size() < 2)
			throw std::runtime_error("Error");
		else if (!isdigit(input[i]) && !is_operator(input[i]) && input[i] != ' ')
			throw std::runtime_error("Error");
	}
	std::cout << _values.top() << std::endl;
}