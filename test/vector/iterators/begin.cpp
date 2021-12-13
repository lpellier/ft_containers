#include "../../../includes/test.hpp"

void	begin() {
	std::vector<int> foo;
	for (int i = 0; i < 10; i++)
		foo.push_back(i);

	CONTAINER	test(foo.begin(), foo.end());

	CONTAINER::iterator it_foo = test.begin();
	std::cout << *it_foo << std::endl;
	it_foo++;
	std::cout << *it_foo << std::endl;
	it_foo--;
	std::cout << *it_foo << std::endl;
}

int main() {
	begin();
	exit(EXIT_SUCCESS);
}
