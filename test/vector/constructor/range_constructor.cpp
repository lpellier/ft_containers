#include "../../../includes/test.hpp"

void	range_constructor() {
	const std::vector<int>	range_guy(10, 1);
	CONTAINER	test(range_guy.begin(), range_guy.end());
	std::for_each(test.begin(), test.end(), _print);
}

int main() {
	range_constructor();
	exit(EXIT_SUCCESS);
}
