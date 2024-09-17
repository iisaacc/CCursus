#include "iter.hpp"



int main()
{
	std::string array = "Hello";
	::iter(&array[0], array.length(), printElement);
	std::cout << std::endl;
	char array2[] = "World";
	::iter(array2, sizeof(array2) - 1, printElement);
	std::cout << std::endl;
	int array3[] = {1, 2, 3, 4, 5};
	::iter(array3, sizeof(array3) / sizeof(array3[0]), printElement);
	std::cout << std::endl;
	float array4[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	::iter(array4, sizeof(array4) / sizeof(array4[0]), printElement);
	return 0;
}