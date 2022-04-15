#include "../../test.hpp"

void	erase() {
	NAMESPACE::map<TEST_TYPE, TEST_TYPE> test;
	for (int i = 0; i < 10; i++)
		test.insert(NAMESPACE::make_pair(i, i));
	_print_map(test);
	test.erase(5);
	_print_map(test);
	test.erase(2);
	_print_map(test);
	test.erase(8);
	_print_map(test);
	test.erase(1);
	_print_map(test);
	test.erase(0);
	_print_map(test);
	test.erase(4);
	_print_map(test);
	test.erase(9);
	_print_map(test);
	test.erase(3);
	_print_map(test);
	test.erase(6);
	_print_map(test);
	test.erase(7);
	_print_map(test);
}

int main() {
	erase();
	exit(EXIT_SUCCESS);
}
