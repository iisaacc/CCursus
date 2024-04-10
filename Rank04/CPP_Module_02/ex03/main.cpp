#include "Point.hpp"

int main( void )
{
	Point a(-2,3);
	Point b(3,-1);
	Point c(5,6);
	Point point(1,1.5);

	if (bsp(a,b,c,point))
		std::cout << "true!" << std::endl;
	else
		std::cout << "flase!" << std::endl;
	return 0;
}
