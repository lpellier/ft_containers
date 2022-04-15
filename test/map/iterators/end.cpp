#include "../../test.hpp"

void	end() {
	NAMESPACE::map<TEST_TYPE, TEST_TYPE> foo;
	for (int i = 0; i < 10; i++)
		foo.insert(NAMESPACE::make_pair(i, i));

	NAMESPACE::map<TEST_TYPE, TEST_TYPE>	test(foo.begin(), foo.end());
	// test.display_tree();

	NAMESPACE::map<TEST_TYPE, TEST_TYPE>::iterator it_foo = test.end();
	NAMESPACE::map<TEST_TYPE, TEST_TYPE>::const_iterator const_it_foo = test.end();
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

	NAMESPACE::map<TEST_TYPE, TEST_TYPE>::iterator test_it = test.begin();
	while (test_it != test.end()) {
		std::cout << (*test_it).first << " " << (*test_it).second << std::endl;
		test_it++;
	}
}

int main() {
	end();
	exit(EXIT_SUCCESS);
}
