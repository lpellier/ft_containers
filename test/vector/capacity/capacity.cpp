#include "../../test.hpp"

void	capacity() {
	NAMESPACE::vector<TEST_TYPE> test1(10, 1);
	NAMESPACE::vector<TEST_TYPE> test2;
	NAMESPACE::vector<TEST_TYPE> test3(test1);
	NAMESPACE::vector<TEST_TYPE> test4(test3.begin(), test3.end());
	std::vector<TEST_TYPE> test5(10, 5);

	test5.assign(70, 8);

	std::cout << test1.capacity() << std::endl;
	std::cout << test2.capacity() << std::endl;
	std::cout << test3.capacity() << std::endl;
	std::cout << test4.capacity() << std::endl;
}

int main() {
	capacity();
	exit(EXIT_SUCCESS);
}
