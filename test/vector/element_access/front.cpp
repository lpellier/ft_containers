#include "../../test.hpp"

void	front() {
	NAMESPACE::vector<TEST_TYPE> test;

	_print_vec(test);
	test.push_back(10);
	std::cout << test.front() << std::endl;
	for (int i = 0; i < 15; i++) {
		test.push_back(i);
		std::cout << test.front() << std::endl;
	}
	_print_vec(test);
	for (int i = 0; i < 15; i++) {
		test.front() = i;
		std::cout << test.front() << std::endl;
	}
	_print_vec(test);
}

int main() {
	front();
	exit(EXIT_SUCCESS);
}
