#include "../../test.hpp"

void	relational_op() {
	NAMESPACE::map<TEST_TYPE, TEST_TYPE> test(100, 5);
	NAMESPACE::map<TEST_TYPE, TEST_TYPE> test1(50, 2);

	std::cout << (test == test1) << std::endl;
	std::cout << (test != test1) << std::endl;
	std::cout << (test < test1) << std::endl;
	std::cout << (test > test1) << std::endl;
	std::cout << (test <= test1) << std::endl;
	std::cout << (test >= test1) << std::endl;
	
	NAMESPACE::map<TEST_TYPE, TEST_TYPE> test2(100, 5);

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
