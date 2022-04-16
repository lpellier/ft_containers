#include "../../test.hpp"

void	empty() {
	NAMESPACE::stack<TEST_TYPE, NAMESPACE::vector<TEST_TYPE> > test;

	std::cout << test.empty();
	test.push(1);
	std::cout << test.empty();
	test.pop();
	std::cout << test.empty();
}

int main() {
	empty();
	exit(EXIT_SUCCESS);
}
