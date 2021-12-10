#include "../../../includes/test.hpp"

void	copy_constructor() {
	CONTAINER	copy_guy(10, 1);
	CONTAINER	test(copy_guy);
	std::for_each(test.begin(), test.end(), _print);
}

int main() {
	copy_constructor();
	exit(EXIT_SUCCESS);
}
