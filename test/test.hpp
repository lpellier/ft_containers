#pragma once

# define CYAN           "\e[34m"
# define RED            "\e[31m"
# define RESET          "\e[0m"

#ifndef NAMESPACE
# define NAMESPACE std
#endif

#ifndef TEST_TYPE
# define TEST_TYPE int
#endif

#include "../includes/containers.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stdlib.h>

void	_print_pair(NAMESPACE::pair<const TEST_TYPE, TEST_TYPE> a) {
	std::cout << a.first << " " << a.second << std::endl;
}

void	_print(int a) {
	std::cout << a << " ";
}

template <typename vector>
void	_print_vec(vector a) {
	std::cout << "Contents : ";
	std::for_each(a.begin(), a.end(), _print);
	std::cout << std::endl;
	std::cout << "Max size : " << a.max_size() << std::endl;
	// std::cout << "Capacity : " << a.capacity() << std::endl;
	std::cout << "Size : " << a.size() << std::endl;
}

/* template for testing
#include "../../test.hpp"

void	templ() {
	CONTAINER test;
}

int main() {
	templ();
	exit(EXIT_SUCCESS);
}
*/
