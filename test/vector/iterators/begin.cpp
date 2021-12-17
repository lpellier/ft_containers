#include "../../test.hpp"

void	begin() {
	std::vector<int> foo;
	for (int i = 0; i < 10; i++)
		foo.push_back(i);

	CONTAINER	test(foo.begin(), foo.end());

	CONTAINER::iterator it_foo = test.begin();
	CONTAINER::const_iterator const_it_foo = test.begin();
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

	CONTAINER::iterator test_it = test.begin();
	while (test_it != test.end()) {
		std::cout << *test_it << std::endl;
		test_it++;
	}
}

int main() {
	begin();
	exit(EXIT_SUCCESS);
}
