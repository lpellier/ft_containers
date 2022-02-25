#include "../../test.hpp"

void	begin() {
	std::vector<NAMESPACE::pair<TEST_TYPE, TEST_TYPE> > foo;
	for (int i = 0; i < 10; i++)
		foo.push_back(NAMESPACE::make_pair(i, i));

	NAMESPACE::map<TEST_TYPE, TEST_TYPE>	test(foo.begin(), foo.end());

	NAMESPACE::map<TEST_TYPE, TEST_TYPE>::iterator it_foo = test.begin();
	NAMESPACE::map<TEST_TYPE, TEST_TYPE>::const_iterator const_it_foo = test.begin();
	std::cout << (*it_foo).first << " " << (*it_foo).second << std::endl;
	it_foo++;
	std::cout << (*it_foo).first << " " << (*it_foo).second << std::endl;
	it_foo--;
	std::cout << (*it_foo).first << " " << (*it_foo).second << std::endl;

	std::cout << (it_foo == const_it_foo) << std::endl;

	std::cout << (*const_it_foo).first << " " << (*const_it_foo).second << std::endl;
	const_it_foo++;
	std::cout << (*const_it_foo).first << " " << (*const_it_foo).second << std::endl;
	const_it_foo--;
	std::cout << (*const_it_foo).first << " " << (*const_it_foo).second << std::endl;

	NAMESPACE::map<TEST_TYPE, TEST_TYPE>::iterator test_it = test.begin();
	while (test_it != test.end()) {
		std::cout << (*test_it).first << " " << (*test_it).second << std::endl;
		test_it++;
	}
}

int main() {
	begin();
	exit(EXIT_SUCCESS);
}
