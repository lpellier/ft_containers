#include "../../test.hpp"

void	rbegin() {
	NAMESPACE::vector<int> foo;
	for (int i = 0; i < 10; i++)
		foo.push_back(i);

	NAMESPACE::vector<TEST_TYPE>	test(foo.rbegin(), foo.rend());

	NAMESPACE::vector<TEST_TYPE>::reverse_iterator it_foo = test.rbegin();
	NAMESPACE::vector<TEST_TYPE>::const_reverse_iterator const_it_foo = test.rbegin();
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

	NAMESPACE::vector<TEST_TYPE>::reverse_iterator test_it = test.rbegin();
	while (test_it != test.rend()) {
		std::cout << *test_it << std::endl;
		test_it++;
	}
}

int main() {
	rbegin();
	exit(EXIT_SUCCESS);
}
