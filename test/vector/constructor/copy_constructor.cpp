#include "../../../containers/vector/vector.hpp"
#include "../../test.hpp"

void	copy_constructor() {
	NAMESPACE::vector<TEST_TYPE>	copy_guy(10, 1);
	NAMESPACE::vector<TEST_TYPE>	test(copy_guy);
	std::for_each(test.begin(), test.end(), _print);
}

int main() {
	copy_constructor();
	exit(EXIT_SUCCESS);
}
