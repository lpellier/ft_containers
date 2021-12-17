#include "../../test.hpp"

void	empty() {
	CONTAINER test;

	std::cout << test.empty();
	test.push_back(1);
	std::cout << test.empty();
	test.pop_back();
	std::cout << test.empty();
}

int main() {
	empty();
	exit(EXIT_SUCCESS);
}
