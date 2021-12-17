#include "../../test.hpp"

void	relational_op() {
	CONTAINER test(100, 5);
	CONTAINER test1(50, 2);

	std::cout << (test == test1) << std::endl;
	std::cout << (test != test1) << std::endl;
	std::cout << (test < test1) << std::endl;
	std::cout << (test > test1) << std::endl;
	std::cout << (test <= test1) << std::endl;
	std::cout << (test >= test1) << std::endl;
	
	CONTAINER test2(100, 5);

	std::cout << (test == test2) << std::endl;
	std::cout << (test != test2) << std::endl;
	std::cout << (test < test2) << std::endl;
	std::cout << (test > test2) << std::endl;
	std::cout << (test <= test2) << std::endl;
	std::cout << (test >= test2) << std::endl;
	
}

int main() {
	relational_op();
	exit(EXIT_SUCCESS);
}
