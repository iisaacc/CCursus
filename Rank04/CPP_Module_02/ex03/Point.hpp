#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point {
	private:
		Fixed x;
		Fixed y;

	public:
		//Constructores y destrusctores
		Point(void);//							Constructor por defecto (inicia x e y a 0)
		Point(float const x, float const y);//	Constructor por parametro 
		Point(const Point &other);//			Constructor de copia
		~Point(void);//							Destructor por defecto
		Point &operator=(const Point &other);//	Operador de asignación

		//Getters & Setters
		Fixed	get_X() const;
		Fixed	get_Y() const;
		void	set_X(Fixed x);
		void	set_Y(Fixed y);
};

bool bsp(const Point a, const Point b, const Point c, const Point point);

#endif