#include "../../test.hpp"

void	rend() {
	NAMESPACE::vector<NAMESPACE::pair<TEST_TYPE, TEST_TYPE> > foo;
	for (int i = 0; i < 10; i++)
		foo.push_back(NAMESPACE::make_pair(i, i));

	NAMESPACE::map<TEST_TYPE, TEST_TYPE>	test(foo.rbegin(), foo.rend());

	NAMESPACE::map<TEST_TYPE, TEST_TYPE>::reverse_iterator it_foo = test.rend();
	NAMESPACE::map<TEST_TYPE, TEST_TYPE>::const_reverse_iterator const_it_foo = test.rend();
	it_foo--;
	std::cout << (*it_foo).first << " " << (*it_foo).second << std::endl;
	it_foo--;
	std::cout << (*it_foo).first << " " << (*it_foo).second << std::endl;
	it_foo++;
	std::cout << (*it_foo).first << " " << (*it_foo).second << std::endl << std::endl;

	const_it_foo--;
	std::cout << (*const_it_foo).first << " " << (*const_it_foo).second << std::endl;
	const_it_foo--;
	std::cout << (*const_it_foo).first << " " << (*const_it_foo).second << std::endl;
	const_it_foo++;
	std::cout << (*const_it_foo).first << " " << (*const_it_foo).second << std::endl << std::endl;

	NAMESPACE::map<TEST_TYPE, TEST_TYPE>::reverse_iterator test_it = test.rend();
	test_it--;
	while (test_it != test.rbegin()) {
		std::cout << (*test_it).first << " " << (*test_it).second << std::endl;
		test_it--;
	}
}

int main() {
	rend();
	exit(EXIT_SUCCESS);
}
