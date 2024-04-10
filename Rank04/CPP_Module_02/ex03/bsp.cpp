#include "Point.hpp"

//	A = (x1*(y2 - y3) + x2*(y3 - y1) + x3(y1 - y2))/2		Fórmula de calculo del área de un triángulo dadas sus coordenadas (Determinante matriz).
static float area (const Point p1, const Point p2, const Point p3)
{
	Fixed	area;

	area = ((p1.get_X() * (p2.get_Y() - p3.get_Y())) + (p2.get_X() * (p3.get_Y() - p1.get_Y())) + (p3.get_X() * (p1.get_Y() - p2.get_Y())))/2;

	if (area.toFloat() < 0)
		area = area * (-1);
	return (area.toFloat());
}

//a, b, c son los vertices del triangulo
//Devuelve true si point esta dentro del triangulo abc. Si el point pertenece en un vertice o lado retorna false.
bool bsp(const Point a, const Point b, const Point c, const Point point)
{
	if (area(a ,b ,point) + area(a, c, point) + area(b, c , point) == area(a, b, c)
		&& area(a ,b ,point) != 0 && area(a, c, point) != 0 && area(b, c , point) != 0)
		return (true);
	else
		return (false);
}