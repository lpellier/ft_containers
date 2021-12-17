#include "../../test.hpp"

void	push_back() {
	CONTAINER test(15, 2);
	_print_vec(test);
	test.push_back(3);
	_print_vec(test);
	test.push_back(3);
	_print_vec(test);
	for (unsigned long i = 0; i < 10000; i++) {
		test.push_back(i);
	}
	_print_vec(test);
}

int main() {
	push_back();
	exit(EXIT_SUCCESS);
}
