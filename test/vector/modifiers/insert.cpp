#include "../../../includes/test.hpp"

void	insert() {
	CONTAINER test(14, 2);
	CONTAINER test1(100, 3);
	_print_vec(test);
	test.insert(test.begin() + 4, 5);
	_print_vec(test);
	test.insert(test.end() - 5, test1.begin(), test1.end());
	_print_vec(test);
	test.insert(test.end() - 5, 13, 6);
	_print_vec(test);
}

int main() {
	insert();
	exit(EXIT_SUCCESS);
}
