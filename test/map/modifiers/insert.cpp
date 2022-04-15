#include "../../test.hpp"

void	insert() {
	NAMESPACE::map<TEST_TYPE, TEST_TYPE> test(14, 2);
	NAMESPACE::map<TEST_TYPE, TEST_TYPE> test1(100, 3);
	_print_map(test);
	test.insert(test.begin() + 4, 5);
	_print_map(test);
	test.insert(test.end() - 5, test1.begin(), test1.end());
	_print_map(test);
	test.insert(test.end() - 5, 13, 6);
	_print_map(test);
}

int main() {
	insert();
	exit(EXIT_SUCCESS);
}
