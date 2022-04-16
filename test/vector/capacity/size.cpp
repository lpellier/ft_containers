#include "../../../containers/vector/vector.hpp"
#include "../../test.hpp"

void	size() {
	NAMESPACE::vector<TEST_TYPE> test;

	std::cout << test.size() << std::endl;
	test.push_back(1);
	std::cout << test.size() << std::endl;
	test.pop_back();
	std::cout << test.size() << std::endl;
	test.assign(200, 1);
	std::cout << test.size() << std::endl;
}

int main() {
	size();
	exit(EXIT_SUCCESS);
}
