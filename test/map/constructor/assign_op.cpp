#include "../../test.hpp"

void	assign_op() {
	std::vector<NAMESPACE::pair<const TEST_TYPE, TEST_TYPE> > test_vec;
	for (int i = 0; i < 10; i++)
		test_vec.push_back(NAMESPACE::make_pair(i, i));
	NAMESPACE::map<TEST_TYPE, TEST_TYPE>	assign_guy(test_vec.begin(), test_vec.end());
	NAMESPACE::map<TEST_TYPE, TEST_TYPE>	test = assign_guy;
	std::for_each(test.begin(), test.end(), _print_pair);

	NAMESPACE::map<TEST_TYPE, TEST_TYPE>	assign_guy2;
	NAMESPACE::map<TEST_TYPE, TEST_TYPE>	test2 = assign_guy2;
	std::for_each(test2.begin(), test2.end(), _print_pair);
}

int main() {
	assign_op();
	exit(EXIT_SUCCESS);
}
