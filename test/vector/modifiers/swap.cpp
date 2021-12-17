#include "../../test.hpp"

void	swap() {
	CONTAINER test(10, 0);
	CONTAINER test1(20, 1);

	_print_vec(test);
	_print_vec(test1);
	test.swap(test1);
	_print_vec(test);
	_print_vec(test1);
	test1.swap(test);
	_print_vec(test);
	_print_vec(test1);
}

int main() {
	swap();
	exit(EXIT_SUCCESS);
}
