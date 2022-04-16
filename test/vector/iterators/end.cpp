#include "../../../containers/vector/vector.hpp"
#include "../../test.hpp"

void	end() {
	NAMESPACE::vector<int> foo;
	for (int i = 0; i < 10; i++)
		foo.push_back(i);

	NAMESPACE::vector<TEST_TYPE>	test(foo.begin(), foo.end());

	NAMESPACE::vector<TEST_TYPE>::iterator it_foo = test.end();
	NAMESPACE::vector<TEST_TYPE>::const_iterator const_it_foo = test.end();
	it_foo--;
	std::cout << *it_foo << std::endl;
	it_foo--;
	std::cout << *it_foo << std::endl;
	it_foo++;
	std::cout << *it_foo << std::endl;

	const_it_foo--;
	std::cout << *const_it_foo << std::endl;
	const_it_foo--;
	std::cout << *const_it_foo << std::endl;
	const_it_foo++;
	std::cout << *const_it_foo << std::endl;

	NAMESPACE::vector<TEST_TYPE>::iterator test_it = test.end();
	while (test_it != test.begin()) {
		test_it--;
		std::cout << *test_it << std::endl;
	}
}

int main() {
	end();
	exit(EXIT_SUCCESS);
}
