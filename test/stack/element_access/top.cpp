#include "../../test.hpp"

void	top() {
	NAMESPACE::stack<TEST_TYPE, NAMESPACE::vector<TEST_TYPE> > test;

	test.push(10);
	std::cout << test.top() << std::endl;
	for (int i = 0; i < 15; i++) {
		test.push(i);
		std::cout << test.top() << std::endl;
	}
	for (int i = 0; i < 15; i++) {
		test.top() = i;
		std::cout << test.top() << std::endl;
	}
}

int main() {
	top();
	exit(EXIT_SUCCESS);
}
