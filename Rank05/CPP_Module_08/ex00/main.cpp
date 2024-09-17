#include "easyfind.hpp"

int main()
{
	int array[] = {1, 2, 3, 4, 5};
	std::vector<int> vec(array, array + sizeof(array) / sizeof(int));
	try {
		std::cout << *easyfind(vec, 10) << std::endl;
	} catch (const std::runtime_error& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}