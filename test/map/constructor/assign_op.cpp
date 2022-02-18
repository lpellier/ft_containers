#include "../../test.hpp"

void	assign_op() {
	NAMESPACE::map<TEST_TYPE, TEST_TYPE>	assign_guy(10, 1);
	NAMESPACE::map<TEST_TYPE, TEST_TYPE>	test = assign_guy;
	std::for_each(test.begin(), test.end(), _print);

	NAMESPACE::map<TEST_TYPE, TEST_TYPE>	assign_guy2;
	NAMESPACE::map<TEST_TYPE, TEST_TYPE>	test2 = assign_guy2;
	std::for_each(test2.begin(), test2.end(), _print);
}

int main() {
	assign_op();
	exit(EXIT_SUCCESS);
}
