#include "../../test.hpp"

// !
# define NAMESPACE ft

void	erase() {
	NAMESPACE::map<TEST_TYPE, TEST_TYPE> test;
	for (int i = 0; i < 10; i++)
		test.insert(NAMESPACE::make_pair(i, i));
	_print_map(test);
	NAMESPACE::map<TEST_TYPE, TEST_TYPE>::iterator test_it = test.begin();
	test.erase(test_it);
	_print_map(test);
	test_it = test.begin();
	test.erase(test_it);
	_print_map(test);
}

int main() {
	erase();
	exit(EXIT_SUCCESS);
}
