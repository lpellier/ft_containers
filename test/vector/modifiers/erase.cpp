#include "../../../containers/vector/vector.hpp"
#include "../../test.hpp"

void	erase() {
	NAMESPACE::vector<TEST_TYPE> test;
	for (int i = 0; i < 10; i++)
		test.push_back(i);
	_print_vec(test);
	test.erase(test.begin() + 5);
	_print_vec(test);
	test.erase(test.begin(), test.begin() + 3);
	_print_vec(test);
}

int main() {
	erase();
	exit(EXIT_SUCCESS);
}
