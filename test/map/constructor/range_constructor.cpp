#include "../../test.hpp"

void	range_constructor() {
	NAMESPACE::map<TEST_TYPE, TEST_TYPE> range_guy;
	for (int i = 0; i < 10; i++)
		range_guy.insert(NAMESPACE::make_pair(i, i));
	NAMESPACE::map<TEST_TYPE, TEST_TYPE>	test(range_guy.begin(), range_guy.end());
	std::for_each(test.begin(), test.end(), _print_pair);
}

int main() {
	range_constructor();
	exit(EXIT_SUCCESS);
}
