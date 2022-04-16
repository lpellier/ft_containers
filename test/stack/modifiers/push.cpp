#include "../../test.hpp"

void	push() {
	NAMESPACE::stack<TEST_TYPE, NAMESPACE::vector<TEST_TYPE> > test(NAMESPACE::vector<TEST_TYPE>(15, 2));

	test.push(3);
	std::cout << test.top() << ' ';
	test.push(3);
	std::cout << test.top() << ' ';
	for (unsigned long i = 0; i < 10000; i++) {
		test.push(i);
	}
	for (unsigned long i = 0; i < 10000; i++) {
		std::cout << test.top() << ' ';
		test.pop();
	}
}

int main() {
	push();
	exit(EXIT_SUCCESS);
}
