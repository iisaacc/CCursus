#include "whatever.hpp"

// int main()
// {
// 	int n = 1;
// 	int m = 10;

// 	std::string s = "hola";
// 	std::string t = "h";
// 	std::cout << "------------TESTING--------------" << std::endl;
// 	swap(n, m);
// 	std::cout << "After swap n: " << n << " m: " << m << std::endl;
// 	swap(s, t);
// 	std::cout << "After swap s: " << s << " t: " << t << std::endl << std::endl;
// 	std::cout << "The max as string is: " << max(s, t) << std::endl;
// 	std::cout << "The min as string is: " << min(s, t) << std::endl << std::endl;
// 	std::cout << "The max as int is: " << max(n, m) << std::endl;
// 	std::cout << "The min as int is: " << min(n, m) << std::endl << std::endl;
// }

// Subject main
int main( void ) {
int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
}