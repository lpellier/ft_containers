#include "../../../containers/stack/stack.hpp"
#include "../../test.hpp"

void	pop() {
	NAMESPACE::stack<TEST_TYPE, NAMESPACE::vector<TEST_TYPE> > test(NAMESPACE::vector<TEST_TYPE>(15, 2));
	
	std::cout << test.top() << " ";
	test.pop();
	std::cout << test.top() << " ";
	test.pop();
	std::cout << test.top() << " ";
	for (; test.size() > 0; test.pop())
		std::cout << test.top() << " ";
	std::cout << std::endl;
}

int main() {
	pop();
	exit(EXIT_SUCCESS);
}
