#include "../../../containers/vector/vector.hpp"
#include "../../test.hpp"

void	pop_back() {
	NAMESPACE::vector<TEST_TYPE> test(15, 2);
	_print_vec(test);
	test.pop_back();
	_print_vec(test);
	test.pop_back();
	_print_vec(test);
	for (NAMESPACE::vector<TEST_TYPE>::iterator it = test.begin(); it != test.end();)
		test.pop_back();
	_print_vec(test);
}

int main() {
	pop_back();
	exit(EXIT_SUCCESS);
}
