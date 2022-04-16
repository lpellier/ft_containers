#include "../../../containers/vector/vector.hpp"
#include "../../test.hpp"

void	swap() {
	NAMESPACE::vector<TEST_TYPE> test(10, 0);
	NAMESPACE::vector<TEST_TYPE> test1(20, 1);

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
