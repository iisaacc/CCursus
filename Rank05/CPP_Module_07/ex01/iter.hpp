#pragma once

#include <iostream>
#include <string>

// Función para imprimir char
template< typename T >
void printElement(T& element) {
    std::cout << element << std::endl;
}

template< typename T>
void	iter(T *array, size_t size, void (*func)(T &)) {
	if (!array || size == 0 || !func) {
		return;
	}
	for (size_t i = 0; i < size; i++) {
		func(array[i]);
	}
}
