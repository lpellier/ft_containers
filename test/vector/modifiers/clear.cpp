#include "../../../includes/test.hpp"

void	clear() {
	CONTAINER to_be_assigned(1000, 10);
	CONTAINER test;

	_print_vec(test);
	test.clear();
	_print_vec(test);
	test = CONTAINER(100, 5);
	test.clear();
	_print_vec(test);
	// test = CONTAINER(to_be_assigned.begin(), to_be_assigned.end());
	test.clear();
	_print_vec(test);
}

int main() {
	clear();
	exit(EXIT_SUCCESS);
}
