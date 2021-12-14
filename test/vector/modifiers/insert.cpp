#include "../../../includes/test.hpp"

void	insert() {
	CONTAINER test(14, 2);
	CONTAINER test1(100, 3);
	std::cout << test.capacity() << std::endl;
	_print_vec(test);
	test.insert(test.begin() + 4, 5);
	std::cout << test.capacity() << std::endl;
	_print_vec(test);
	test.insert(test.end() - 5, test1.begin(), test1.end());
	std::cout << test.capacity() << std::endl;
	_print_vec(test);
	test.insert(test.end() - 5, 13, 6);
	std::cout << test.capacity() << std::endl;
	_print_vec(test);
}

int main() {
	insert();
	exit(EXIT_SUCCESS);
}
