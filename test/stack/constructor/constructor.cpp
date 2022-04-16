#include "../../test.hpp"
#include <list>

void	default_constructor() {
	NAMESPACE::stack<TEST_TYPE, NAMESPACE::vector<TEST_TYPE> >	test(NAMESPACE::vector<TEST_TYPE>(100, 5));
	while (test.size() > 0) {
		std::cout << test.top() << " ";
		test.pop();
	}
	std::cout << std::endl;
	NAMESPACE::stack<TEST_TYPE, std::list<TEST_TYPE> >	test2(std::list<TEST_TYPE>(100, 5));
	while (test2.size() > 0) {
		std::cout << test2.top() << " ";
		test2.pop();
	}
	std::cout << std::endl;
}

int main() {
	default_constructor();
	exit(EXIT_SUCCESS);
}
