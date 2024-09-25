#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <algorithm>

template < typename T >
typename T::iterator easyfind(T &container, int n)
{
 	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw std::runtime_error("Value not found in container");
	return (it);
}