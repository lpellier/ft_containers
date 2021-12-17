#include "../../test.hpp"

void	max_size() {
	CONTAINER test;

	std::cout << test.max_size() << std::endl;
	test.push_back(1);
	std::cout << test.max_size() << std::endl;
}

int main() {
	max_size();
	exit(EXIT_SUCCESS);
}
