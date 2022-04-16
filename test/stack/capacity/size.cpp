#include "../../test.hpp"

void	size() {
	NAMESPACE::stack<TEST_TYPE, NAMESPACE::vector<TEST_TYPE> > test;

	std::cout << test.size() << std::endl;
	test.push(1);
	std::cout << test.size() << std::endl;
	test.pop();
	std::cout << test.size() << std::endl;
	for (int i = 0; i < 200; i++) {
		test.push(i);
	}
	std::cout << test.size() << std::endl;
}

int main() {
	size();
	exit(EXIT_SUCCESS);
}
