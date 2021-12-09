#include "../../includes/test.hpp"

int main() {
	CONTAINER	copy_guy(10, 1);
	CONTAINER	test(copy_guy);
	std::for_each(test.begin(), test.end(), _print);
	exit(EXIT_SUCCESS);
}
