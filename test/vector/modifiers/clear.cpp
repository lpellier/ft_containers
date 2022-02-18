#include "../../test.hpp"

void	clear() {
	NAMESPACE::vector<TEST_TYPE> to_be_assigned(1000, 10);
	NAMESPACE::vector<TEST_TYPE> test;
	NAMESPACE::vector<TEST_TYPE> test1;

	_print_vec(test);
	test.clear();
	_print_vec(test);
	test = NAMESPACE::vector<TEST_TYPE>(100, 5);
	test.clear();
	_print_vec(test1);
	test1 = NAMESPACE::vector<TEST_TYPE>(to_be_assigned.begin(), to_be_assigned.end());
	test1.clear();
	_print_vec(test1);
}

int main() {
	clear();
	exit(EXIT_SUCCESS);
}
