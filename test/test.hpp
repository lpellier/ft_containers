#pragma once

# define CYAN           "\e[34m"
# define RED            "\e[31m"
# define RESET          "\e[0m"

#ifndef NAMESPACE
# define NAMESPACE ft
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

void	_print_pair(const NAMESPACE::pair<const TEST_TYPE, TEST_TYPE> & a) {
	std::cout << a.first << " " << a.second << " | ";
}

void	_print(const int & a) {
	std::cout << a << " ";
}

template <typename vector>
void	_print_vec(const vector & a) {
	std::cout << "Contents : ";
	std::for_each(a.begin(), a.end(), _print);
	std::cout << std::endl;
	std::cout << "Max size : " << a.max_size() << std::endl;
	std::cout << "Size : " << a.size() << std::endl;
}

template <typename map>
void	_print_map(const map & a) {
	std::cout << "Contents : | ";
	// std::for_each(a.begin(), a.end(), _print_pair);
	typename map::const_iterator it = a.begin();
	while (it != a.end()) {
		_print_pair(*it);
		it++;
	}
	std::cout << std::endl;
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
