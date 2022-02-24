#include "../../test.hpp"

void	copy_constructor() {
	std::vector<NAMESPACE::pair<const TEST_TYPE, TEST_TYPE> > test_vec;
	for (int i = 0; i < 10; i++)
		test_vec.push_back(NAMESPACE::make_pair(i, i));
	NAMESPACE::map<TEST_TYPE, TEST_TYPE>	copy_guy(test_vec.begin(), test_vec.end());
	NAMESPACE::map<TEST_TYPE, TEST_TYPE>	test(copy_guy);
	std::for_each(test.begin(), test.end(), _print_pair);
}

int main() {
	copy_constructor();
	exit(EXIT_SUCCESS);
}
