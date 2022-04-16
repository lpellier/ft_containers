#include "../../test.hpp"

void	relational_op() {
	NAMESPACE::stack<TEST_TYPE, NAMESPACE::vector<TEST_TYPE> > test(NAMESPACE::vector<TEST_TYPE>(100, 5));
	NAMESPACE::stack<TEST_TYPE, NAMESPACE::vector<TEST_TYPE> > test1(NAMESPACE::vector<TEST_TYPE>(50, 2));

	std::cout << (test == test1) << std::endl;
	std::cout << (test != test1) << std::endl;
	std::cout << (test < test1) << std::endl;
	std::cout << (test > test1) << std::endl;
	std::cout << (test <= test1) << std::endl;
	std::cout << (test >= test1) << std::endl;
	
	NAMESPACE::stack<TEST_TYPE, NAMESPACE::vector<TEST_TYPE> > test2(NAMESPACE::vector<TEST_TYPE>(100, 5));

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
