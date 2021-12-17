#include "../../test.hpp"

void	clear() {
	CONTAINER to_be_assigned(1000, 10);
	CONTAINER test;
	CONTAINER test1;

	_print_vec(test);
	test.clear();
	_print_vec(test);
	test = CONTAINER(100, 5);
	test.clear();
	_print_vec(test1);
	test1 = CONTAINER(to_be_assigned.begin(), to_be_assigned.end());
	test1.clear();
	_print_vec(test1);
}

int main() {
	clear();
	exit(EXIT_SUCCESS);
}
