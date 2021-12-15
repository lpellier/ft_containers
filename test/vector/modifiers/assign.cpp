#include "../../../includes/test.hpp"

void	assign() {
	std::vector<int> to_be_assigned;
	for (int i = 0; i < 100; i++)
		to_be_assigned.push_back(i);
	
	CONTAINER test(10, 2);

	_print_vec(test);
	test.assign(to_be_assigned.begin(), to_be_assigned.end());
	_print_vec(test);
	test.assign(50, 5);
	_print_vec(test);
	test.assign(1, 5);
	_print_vec(test);
	test.assign(0, 0);
	_print_vec(test);
}

int main() {
	assign();
	exit(EXIT_SUCCESS);
}
