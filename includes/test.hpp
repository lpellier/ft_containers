#ifndef TEST_HPP
# define TEST_HPP

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

template <typename container>
int		constructor();

#endif
