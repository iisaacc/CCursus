#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &obj) {
	(void)obj;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &obj) {
	(void)obj;
	return (*this);
}

void	ScalarConverter::convert(std::string literal) {
	char	*end; //Declara un puntero que std::strtod usará para indicar dónde terminó la conversión.
	double	d;
	std::string modifiedLiteral;
	
	
	errno = 0; //Reinicia errno para asegurarse de que no haya errores previos afectando el código.
	end = NULL;
	if (literal == "nan" || literal == "+inf" || literal == "-inf" 
		|| literal == "+inff" || literal == "-inff" || literal == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (literal == "+inff" || literal == "-inff" || literal == "nanf")
			std::cout << "float: " << literal << std::endl;
		else
			std::cout << "float: " << literal << "f" << std::endl;
		if (literal == "+inff" || literal == "-inff" || literal == "nanf") {
			modifiedLiteral = literal.substr(0, literal.size() - 1); // Quita el último carácter
			std::cout << "double: " << modifiedLiteral << std::endl;
		}
		return ;
	}
	if ((literal[0] >= '0' && literal[0] <= '9') || literal[0] == '-' || literal[0] == '+')
		d = std::strtod(literal.c_str(), &end); //std::strtod procesa tantos caracteres como sea posible para formar un número válido y apunta end al carácter siguiente después del último utilizado en la conversión.
	else if (literal.length() == 1)
		d = static_cast<double>(literal[0]);
	else {
		std::cerr << "Error: Invalid input" << std::endl;
		return ;
	}
	if (errno == ERANGE && (d == std::numeric_limits<double>::infinity()
		|| d == -std::numeric_limits<double>::infinity())) {
				std::cerr << "Error: Value out of range" << std::endl;
				return ;
		}
	
	if ((d >= 0 && d <= 31) || d == 127 || d < 0)
		std::cout << "char: Non displayable" << std::endl;
	else if (d >= std::numeric_limits<char>::min() && d <= std::numeric_limits<char>::max())
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;

	if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max()) {
		int i = static_cast<int>(d);
		std::cout << "int: " << i << std::endl;
	} else {
		std::cout << "int: impossible" << std::endl;
	}

	std::cout << std::fixed << std::setprecision(1);
	// Conversion to float
	float f = static_cast<float>(d);
	if (std::floor(f) == f)
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
	if (end == literal.c_str()) {
		std::cerr << "double: Error: Invalid input" << std::endl;
	}
	else if (std::floor(d) == d)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;

}