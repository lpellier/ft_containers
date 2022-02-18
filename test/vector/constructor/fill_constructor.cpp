#include "../../test.hpp"

void	fill_constructor() {
	NAMESPACE::vector<TEST_TYPE>	test(10, 1);
	std::for_each(test.begin(), test.end(), _print);
}

int main() {
	fill_constructor();
	exit(EXIT_SUCCESS);
}
