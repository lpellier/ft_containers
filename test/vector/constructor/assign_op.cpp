#include "../../../includes/test.hpp"

void	assign_op() {
	CONTAINER	assign_guy(10, 1);
	CONTAINER	test = assign_guy;
	std::for_each(test.begin(), test.end(), _print);

	CONTAINER	assign_guy2;
	CONTAINER	test2 = assign_guy2;
	std::for_each(test2.begin(), test2.end(), _print);
}

int main() {
	assign_op();
	exit(EXIT_SUCCESS);
}
