#include "../../../includes/test.hpp"

void	it_conversion() {
	CONTAINER test(1, 1);

	CONTAINER::const_iterator it_foo_beg = test.begin();
	CONTAINER::const_iterator it_foo_end = test.end();
	std::cout << *it_foo_beg << std::endl;
	std::cout << *it_foo_end << std::endl;
}

int main() {
	it_conversion();
	exit(EXIT_SUCCESS);
}