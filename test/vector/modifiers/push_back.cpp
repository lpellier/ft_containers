#include "../../../includes/test.hpp"

void	push_back() {
	CONTAINER test(15, 2);
	std::cout << test.capacity() << std::endl;
	_print_vec(test);
	test.push_back(3);
	std::cout << test.capacity() << std::endl;
	_print_vec(test);
	test.push_back(3);
	std::cout << test.capacity() << std::endl;
	_print_vec(test);
}

int main() {
	push_back();
	exit(EXIT_SUCCESS);
}
