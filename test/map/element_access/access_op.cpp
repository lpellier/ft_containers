#include "../../../containers/map/map.hpp"
#include "../../test.hpp"

void	access_op() {
	NAMESPACE::map<TEST_TYPE, TEST_TYPE> test;

	_print_map(test);
	for (int i = 0; i < 10; i++)
		test.insert(NAMESPACE::make_pair(i, i));
	_print_map(test);
	for (int i = 0; i < 10; i++)
		std::cout << test[i] << std::endl;
	for (int i = 0; i < 10; i++)
		test[i] = i * 2;
	_print_map(test);
}

int main() {
	access_op();
	exit(EXIT_SUCCESS);
}
