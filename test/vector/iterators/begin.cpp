#include "../../../containers/vector/vector.hpp"
#include "../../test.hpp"

void	begin() {
	NAMESPACE::vector<int> foo;
	for (int i = 0; i < 10; i++)
		foo.push_back(i);


	NAMESPACE::vector<TEST_TYPE>	test(foo.begin(), foo.end());

	NAMESPACE::vector<TEST_TYPE>::iterator it_foo = test.begin();
	NAMESPACE::vector<TEST_TYPE>::const_iterator const_it_foo = test.begin();
	std::cout << *it_foo << std::endl;
	it_foo++;
	std::cout << *it_foo << std::endl;
	it_foo--;
	std::cout << *it_foo << std::endl;

	std::cout << *const_it_foo << std::endl;
	const_it_foo++;
	std::cout << *const_it_foo << std::endl;
	const_it_foo--;
	std::cout << *const_it_foo << std::endl;

	NAMESPACE::vector<TEST_TYPE>::iterator test_it = test.begin();
	while (test_it != test.end()) {
		std::cout << *test_it << std::endl;
		test_it++;
	}
}

int main() {
	begin();
	exit(EXIT_SUCCESS);
}
