#ifndef TEST_HPP
# define TEST_HPP

# define CYAN           "\e[34m"
# define RED            "\e[31m"
# define RESET          "\e[0m"

#include "vector.hpp"
#include <vector>

void	testVector(std::vector<int> & act_vec, ft::vector<int> & my_vec);
void	testIterator(std::vector<int> & actual_vector, ft::vector<int> & my_vector);


void	testVector(const std::vector<int> & act_vec, const ft::vector<int> & my_vec);
void	testIterator(const std::vector<int> & actual_vector, const ft::vector<int> & my_vector);

#endif
