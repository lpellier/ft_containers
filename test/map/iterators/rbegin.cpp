#include "../../../containers/map/map.hpp"
#include "../../test.hpp"

void	rbegin() {
	NAMESPACE::map<TEST_TYPE, TEST_TYPE> foo;
	for (int i = 0; i < 10; i++)
		foo.insert(NAMESPACE::make_pair(i, i));

	NAMESPACE::map<TEST_TYPE, TEST_TYPE>	test(foo.rbegin(), foo.rend());

	NAMESPACE::map<TEST_TYPE, TEST_TYPE>::reverse_iterator it_foo = test.rbegin();
	NAMESPACE::map<TEST_TYPE, TEST_TYPE>::const_reverse_iterator const_it_foo = test.rbegin();
	std::cout << (*it_foo).first << " " << (*it_foo).second << std::endl;
	it_foo++;
	std::cout << (*it_foo).first << " " << (*it_foo).second << std::endl;
	it_foo--;
	std::cout << (*it_foo).first << " " << (*it_foo).second << std::endl << std::endl;

	std::cout << (*const_it_foo).first << " " << (*const_it_foo).second << std::endl;
	const_it_foo++;
	std::cout << (*const_it_foo).first << " " << (*const_it_foo).second << std::endl;
	const_it_foo--;
	std::cout << (*const_it_foo).first << " " << (*const_it_foo).second << std::endl << std::endl;

	NAMESPACE::map<TEST_TYPE, TEST_TYPE>::reverse_iterator test_it = test.rbegin();
	while (test_it != test.rend()) {
		std::cout << (*test_it).first << " " << (*test_it).second << std::endl;
		test_it++;
	}
}

int main() {
	rbegin();
	exit(EXIT_SUCCESS);
}
