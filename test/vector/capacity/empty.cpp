#include "../../../containers/vector/vector.hpp"
#include "../../test.hpp"

void	empty() {
	NAMESPACE::vector<TEST_TYPE> test;

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
