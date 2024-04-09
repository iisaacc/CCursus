#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point {
	private:
		const Fixed x;
		const Fixed y;

	public:
		Point(void);//							Constructor por defecto
		Point(float const x, float const y);//	Constructor por parametro
		~Point(void);//							Destructor por defecto
		Point(const Point &other);//			Constructor de copia
		Point &operator=(const Point &other);//	Operador de asignación
};

#endif