#include "../../test.hpp"

void	pop_back() {
	CONTAINER test(15, 2);
	_print_vec(test);
	test.pop_back();
	_print_vec(test);
	test.pop_back();
	_print_vec(test);
	for (CONTAINER::iterator it = test.begin(); it != test.end();)
		test.pop_back();
	_print_vec(test);
}

int main() {
	pop_back();
	exit(EXIT_SUCCESS);
}
