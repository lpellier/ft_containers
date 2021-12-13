#pragma once

# define CYAN           "\e[34m"
# define RED            "\e[31m"
# define RESET          "\e[0m"

#ifndef CONTAINER
# define CONTAINER const std::vector<int>
#endif

#include "containers.hpp"
#include <vector>
#include <algorithm>
#include <stdlib.h>

void	_print(int a) {
	std::cout << a << std::endl; 
}

/* template for testing
#include "../../../includes/test.hpp"

void	templ() {
	CONTAINER test;
}

int main() {
	templ();
	exit(EXIT_SUCCESS);
}
*/
