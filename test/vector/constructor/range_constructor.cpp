#include "../../../containers/vector/vector.hpp"
#include "../../test.hpp"

void	range_constructor() {
	const NAMESPACE::vector<int>	range_guy(10, 1);
	NAMESPACE::vector<TEST_TYPE>	test(range_guy.begin(), range_guy.end());
	std::for_each(test.begin(), test.end(), _print);
}

int main() {
	range_constructor();
	exit(EXIT_SUCCESS);
}
