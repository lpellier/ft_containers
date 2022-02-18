#include "../../test.hpp"

void	empty() {
	NAMESPACE::map<TEST_TYPE, TEST_TYPE> test;

	std::cout << test.empty();
	test.insert(NAMESPACE::make_pair(TEST_TYPE(), TEST_TYPE()));
	std::cout << test.empty();
	test.clear();
	std::cout << test.empty();
}

int main() {
	empty();
	exit(EXIT_SUCCESS);
}
