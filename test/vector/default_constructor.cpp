#include "../../includes/test.hpp"

int main() {
	CONTAINER	test;
	std::for_each(test.begin(), test.end(), _print);
	exit(EXIT_SUCCESS);
}
