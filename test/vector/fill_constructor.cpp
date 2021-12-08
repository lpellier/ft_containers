#include "../../includes/test.hpp"

int main() {
	CONTAINER	test(10, 1);
	std::for_each(test.begin(), test.end(), _print);
}
