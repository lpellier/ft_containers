#include "../../test.hpp"

void	swap() {
	NAMESPACE::map<TEST_TYPE, TEST_TYPE> test(10, 0);
	NAMESPACE::map<TEST_TYPE, TEST_TYPE> test1(20, 1);

	_print_map(test);
	_print_map(test1);
	test.swap(test1);
	_print_map(test);
	_print_map(test1);
	test1.swap(test);
	_print_map(test);
	_print_map(test1);
}

int main() {
	swap();
	exit(EXIT_SUCCESS);
}
