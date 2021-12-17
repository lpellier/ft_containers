#include "../../test.hpp"

void	rbegin() {
	std::vector<int> foo;
	for (int i = 0; i < 10; i++)
		foo.push_back(i);

	CONTAINER	test(foo.rbegin(), foo.rend());

	CONTAINER::reverse_iterator it_foo = test.rbegin();
	CONTAINER::const_reverse_iterator const_it_foo = test.rbegin();
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

	CONTAINER::reverse_iterator test_it = test.rbegin();
	while (test_it != test.rend()) {
		std::cout << *test_it << std::endl;
		test_it++;
	}
}

int main() {
	rbegin();
	exit(EXIT_SUCCESS);
}
