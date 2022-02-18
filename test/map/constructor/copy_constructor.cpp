#include "../../test.hpp"

void	copy_constructor() {
	NAMESPACE::map<TEST_TYPE, TEST_TYPE>	copy_guy(10, 1);
	NAMESPACE::map<TEST_TYPE, TEST_TYPE>	test(copy_guy);
	std::for_each(test.begin(), test.end(), _print);
}

int main() {
	copy_constructor();
	exit(EXIT_SUCCESS);
}
