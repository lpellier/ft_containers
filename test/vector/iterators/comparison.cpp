#include "../../../containers/vector/vector.hpp"
#include "../../test.hpp"

void	comparison() {
	NAMESPACE::vector<int> foo;
	for (int i = 0; i < 10; i++)
		foo.push_back(i);


	NAMESPACE::vector<TEST_TYPE>	test(foo.begin(), foo.end());

	NAMESPACE::vector<TEST_TYPE>::iterator it_foo = test.begin();
	NAMESPACE::vector<TEST_TYPE>::const_iterator const_it_foo = test.end();

	std::cout << (it_foo > const_it_foo) << std::endl;
	std::cout << (it_foo >= const_it_foo) << std::endl;
	std::cout << (it_foo < const_it_foo) << std::endl;
	std::cout << (it_foo <= const_it_foo) << std::endl;
	std::cout << (it_foo == const_it_foo) << std::endl;
	std::cout << (it_foo != const_it_foo) << std::endl;
}

int main() {
	comparison();
	exit(EXIT_SUCCESS);
}
