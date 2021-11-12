#include "test.hpp"
#include <stdlib.h>

int main() {
	std::vector<int>	template_vector(0);
	for (int i = 0; i < 10; i++)
		template_vector.push_back(i);
	// const std::vector<int>		actual_const_vector(template_vector);	
	// const ft::vector<int>		my_const_vector(template_vector.begin(), template_vector.end());
	// std::vector<int>			actual_vector(template_vector);
	ft::vector<int>				my_vector(template_vector.begin(), template_vector.end());

	ft::vector<int>::const_iterator it_foo = my_vector.begin();
	std::cout << *it_foo;

	// testIterator(actual_vector, my_vector);
	// testIterator(actual_const_vector, my_const_vector);

	// testReverseIterator(actual_vector, my_vector);
	
	// testVector(actual_vector, my_vector);
	// testVector(actual_const_vector, my_const_vector);
	exit(EXIT_SUCCESS);
}
