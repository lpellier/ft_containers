#include "../../test.hpp"

void	resize() {
	NAMESPACE::vector<TEST_TYPE> test;

	_print_vec(test);
	test.resize(100, 5);
	_print_vec(test);
	test.resize(10);
	_print_vec(test);
	test.resize(1000, 6);
	_print_vec(test);
	test.resize(0);
	_print_vec(test);
}

int main() {
	resize();
	exit(EXIT_SUCCESS);
}
