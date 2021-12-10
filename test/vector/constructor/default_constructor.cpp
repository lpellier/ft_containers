#include "../../../includes/test.hpp"

void	default_constructor() {
	CONTAINER	test;
	std::for_each(test.begin(), test.end(), _print);
}

int main() {
	default_constructor();
	exit(EXIT_SUCCESS);
}
