#include "../../test.hpp"

void	back() {
	NAMESPACE::vector<TEST_TYPE> test;

	_print_vec(test);
	test.push_back(10);
	std::cout << test.back() << std::endl;
	for (int i = 0; i < 15; i++) {
		test.push_back(i);
		std::cout << test.back() << std::endl;
	}
	_print_vec(test);
	for (int i = 0; i < 15; i++) {
		test.back() = i;
		std::cout << test.back() << std::endl;
	}
	_print_vec(test);
}

int main() {
	back();
	exit(EXIT_SUCCESS);
}
