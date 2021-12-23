#include "../../test.hpp"
#include "time.h"
#include "stdlib.h"

void	test() {
	srand(time(NULL));
	std::vector<int> test_vec;
	for (int i = 0; i < 15; i++) {
		test_vec.push_back(i);
	}

	ft::map<int, int> test(test_vec.begin(), test_vec.end());
}

int main() {
	test();
	exit(EXIT_SUCCESS);
}