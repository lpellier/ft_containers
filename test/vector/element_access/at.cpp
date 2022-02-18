#include "../../test.hpp"

void	at() {
	NAMESPACE::vector<TEST_TYPE> test;

	_print_vec(test);
	for (int i = 0; i < 10; i++)
		test.push_back(i * 2);
	for (int i = 0; i < 10; i++)
		std::cout << test.at(i) << std::endl;
	for (int i = 0; i < 10; i++)
		test.at(i) = i;
	_print_vec(test);

	// try {
	// 	test.at(10);
	// }
	// catch (std::exception & e) {
	// 	std::cout << e.what() << std::endl;
	// }
}

int main() {
	at();
	exit(EXIT_SUCCESS);
}