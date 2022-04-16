#include "../../../containers/vector/vector.hpp"
#include "../../test.hpp"

void	assign_op() {
	NAMESPACE::vector<TEST_TYPE>	assign_guy(10, 1);
	NAMESPACE::vector<TEST_TYPE>	test = assign_guy;
	std::for_each(test.begin(), test.end(), _print);

	NAMESPACE::vector<TEST_TYPE>	assign_guy2;
	NAMESPACE::vector<TEST_TYPE>	test2 = assign_guy2;
	std::for_each(test2.begin(), test2.end(), _print);
}

int main() {
	assign_op();
	exit(EXIT_SUCCESS);
}
