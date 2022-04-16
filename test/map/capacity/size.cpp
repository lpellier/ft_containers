#include "../../../containers/map/map.hpp"
#include "../../test.hpp"

void	size() {
	NAMESPACE::map<TEST_TYPE, TEST_TYPE> test;

	std::cout << test.size() << std::endl;
	test.insert(NAMESPACE::make_pair(TEST_TYPE(), TEST_TYPE()));
	std::cout << test.size() << std::endl;
	test.clear();
	std::cout << test.size() << std::endl;
	for (int i = 0; i < 4; i++)
		test.insert(NAMESPACE::make_pair(i, i));
	std::cout << test.size() << std::endl;
}

int main() {
	size();
	exit(EXIT_SUCCESS);
}
