#include "../../test.hpp"

void	default_constructor() {
	NAMESPACE::map<TEST_TYPE, TEST_TYPE>	test;
	std::for_each(test.begin(), test.end(), _print);
}

int main() {
	default_constructor();
	exit(EXIT_SUCCESS);
}