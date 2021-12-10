#include "../../../includes/test.hpp"

void	fill_constructor() {
	CONTAINER	test(10, 1);
	std::for_each(test.begin(), test.end(), _print);
}

int main() {
	fill_constructor();
	exit(EXIT_SUCCESS);
}
