#include "../../test.hpp"

void	clear() {
	NAMESPACE::map<TEST_TYPE, TEST_TYPE> to_be_assigned(1000, 10);
	NAMESPACE::map<TEST_TYPE, TEST_TYPE> test;
	NAMESPACE::map<TEST_TYPE, TEST_TYPE> test1;

	_print_map(test);
	test.clear();
	_print_map(test);
	test = NAMESPACE::map<TEST_TYPE, TEST_TYPE>(100, 5);
	test.clear();
	_print_map(test1);
	test1 = NAMESPACE::map<TEST_TYPE, TEST_TYPE>(to_be_assigned.begin(), to_be_assigned.end());
	test1.clear();
	_print_map(test1);
}

int main() {
	clear();
	exit(EXIT_SUCCESS);
}
