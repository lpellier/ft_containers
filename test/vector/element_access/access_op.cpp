#include "../../test.hpp"

void	access_op() {
	NAMESPACE::vector<TEST_TYPE> test;

	_print_vec(test);
	for (int i = 0; i < 10; i++)
		test.push_back(i);
	_print_vec(test);
	for (int i = 0; i < 10; i++)
		std::cout << test[i] << std::endl;
	for (int i = 0; i < 10; i++)
		test[i] = i * 2;
	_print_vec(test);
}

int main() {
	access_op();
	exit(EXIT_SUCCESS);
}
