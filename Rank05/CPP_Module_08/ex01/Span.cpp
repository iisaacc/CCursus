#include "Span.hpp"

Span::Span() : _N(10) {
	std::cout << "Default span created with 10 slots." << std::endl;
}

Span::Span(unsigned int N) : _N(N) {
	std::cout << "Span created with " << N << " slots." << std::endl;
}

Span::~Span() {
	std::cout << "Default destructor called." << std::endl;
}

Span::Span(const Span &other) : _N(other._N), _vec(other._vec) {
	std::cout << "Copy constructor called." << std::endl;
}

Span &Span::operator=(const Span &other) {
	if (this != &other)
	{
		this->_N = other._N;
		this->_vec = other._vec;
	}
	return (*this);
}

void	Span::addNumber(int number) {
	if (_vec.size() >= _N)
		throw Span::ReachedMaxSizeException();
	_vec.push_back(number);
}

const char	*Span::NotEnoughNumbersException::what()const throw() {
	return ("Error: not enough numbers to proceed the check.");
}

const char	*Span::ReachedMaxSizeException::what()const throw() {
	return ("Error: Max size reached.");
}

int	Span::longestSpan() {
	if (this->_vec.size() < 2)
		throw Span::NotEnoughNumbersException();

	std::vector<int>::iterator max = std::max_element(_vec.begin(), _vec.end());
	std::vector<int>::iterator min = std::min_element(_vec.begin(), _vec.end());

	return (*max - *min);
}

int	Span::shortestSpan() {
	int span;
	int min_span;
	std::vector<int> vec_copy = _vec;

	if (this->_vec.size() < 2)
		throw Span::NotEnoughNumbersException();
	std::sort(vec_copy.begin(), vec_copy.end());
	min_span = std::numeric_limits<int>::max();
	for (std::vector<int>::iterator it = vec_copy.begin(); it != vec_copy.end() - 1; ++it)
	{
		span = *(it + 1) - *it;
		if (span < min_span)
			min_span = span;
	}
	return (min_span);
}

void	Span::randomFillVector(int N) {

	srand(static_cast<unsigned int>(time(0)));

	std::vector<int> v;
	
	if (_vec.size() + N > _N)
		throw Span::ReachedMaxSizeException();
	for (int i = 0; i < N; i++)
		v.push_back(rand());
	_vec.insert(_vec.end(), v.begin(), v.end());
}

void	Span::printVector() {
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}