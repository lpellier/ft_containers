#include "../../../includes/test.hpp"

void	it_conversion() {
	CONTAINER test(1, 1);

	// CONTAINER::const_iterator it_foo = test.begin();
	// CONTAINER::const_iterator it_foo = test.end();
	std::cout << *it_foo << std::endl;
}

int main() {
	it_conversion();
	exit(EXIT_SUCCESS);
}