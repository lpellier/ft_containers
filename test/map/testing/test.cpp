#include "../../test.hpp"
#include "time.h"
#include "stdlib.h"
#include <map>
#include <utility>

template < class InputIterator >
void	_display_tree(InputIterator first, InputIterator end) {
	while (first != end) {
		std::cout << (*first).second << std::endl;
		first++;
	}
}

void	printNbr(ft::pair<int, int> & nbr) {
	std::cout << nbr.first << std::endl;
}

void	test() {
	srand(time(NULL));
	std::vector<ft::pair<const int, int> > test_vec;
	for (int i = 0; i < 150; i++) {
		int random = rand() % 150 + 1;
		if (i == 25)
			test_vec.push_back(ft::make_pair(25, 25));
		if (i == 50)
			test_vec.push_back(ft::make_pair(50, 50));
		if (i == 100)
			test_vec.push_back(ft::make_pair(100, 100));
		if (i == 125)
			test_vec.push_back(ft::make_pair(125, 125));
		test_vec.push_back(ft::make_pair(random, random));
	}

	ft::map<int, int> test(test_vec.begin(), test_vec.end());
	test.display_tree();
	// test.erase(25);
	// test.erase(50);
	// test.erase(100);
	// test.erase(125);
	// test.display_tree();
}

int main() {
	test();
	exit(EXIT_SUCCESS);
}
