#include "../../test.hpp"

void	reserve() {
	NAMESPACE::vector<TEST_TYPE> test;

	_print_vec(test);
	test.reserve(100);
	_print_vec(test);
	test.reserve(0);
	_print_vec(test);
	test.reserve(15);
	_print_vec(test);
	test.reserve(260);
	_print_vec(test);
}

int main() {
	reserve();
	exit(EXIT_SUCCESS);
}
