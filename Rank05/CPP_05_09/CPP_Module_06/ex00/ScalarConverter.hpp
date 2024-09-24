
#include <string>
#include <iostream>
#include <cmath>
#include <cerrno>
#include <limits>
#include <cstdlib>
#include <iomanip>



class ScalarConverter {
	public:
		static void	convert(std::string literal);
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(ScalarConverter const &obj);
		ScalarConverter &operator=(ScalarConverter const &obj);
};