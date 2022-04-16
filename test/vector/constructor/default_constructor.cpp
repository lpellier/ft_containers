#include "../../../containers/vector/vector.hpp"
#include "../../test.hpp"

void	default_constructor() {
	NAMESPACE::vector<TEST_TYPE>	test;
	std::for_each(test.begin(), test.end(), _print);
}

int main() {
	default_constructor();
	exit(EXIT_SUCCESS);
}
