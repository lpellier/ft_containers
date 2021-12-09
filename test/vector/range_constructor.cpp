#include "../../includes/test.hpp"

int main() {
	const std::vector<int>	range_guy(10, 1);
	CONTAINER	test(range_guy.begin(), range_guy.end());
	std::for_each(test.begin(), test.end(), _print);
	exit(EXIT_SUCCESS);
}
