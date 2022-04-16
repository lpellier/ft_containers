#include "../../../containers/map/map.hpp"
#include "../../test.hpp"

void	copy_constructor() {
	NAMESPACE::map<TEST_TYPE, TEST_TYPE> test_map;
	for (int i = 0; i < 10; i++)
		test_map.insert(NAMESPACE::make_pair(i, i));
	NAMESPACE::map<TEST_TYPE, TEST_TYPE>	copy_guy(test_map.begin(), test_map.end());
	NAMESPACE::map<TEST_TYPE, TEST_TYPE>	test(copy_guy);
	std::for_each(test.begin(), test.end(), _print_pair);
}

int main() {
	copy_constructor();
	exit(EXIT_SUCCESS);
}
