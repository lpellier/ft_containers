#include "../../../includes/test.hpp"

void	capacity() {
	CONTAINER test1(10, 1);
	CONTAINER test2;
	CONTAINER test3(test1);
	CONTAINER test4(test3.begin(), test3.end());

	std::cout << test1.capacity() << std::endl;
	std::cout << test2.capacity() << std::endl;
	std::cout << test3.capacity() << std::endl;
	std::cout << test4.capacity() << std::endl;
}

int main() {
	capacity();
	exit(EXIT_SUCCESS);
}
