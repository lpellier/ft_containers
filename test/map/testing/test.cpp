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
		// test_vec.push_back(ft::make_pair(i, i));
	}

	ft::map<int, int> test_map(test_vec.begin(), test_vec.end());
	test_map.display_tree();
	// std::cout << "map size is " << test_map.size() << std::endl;
	
	ft::map<int, int>::iterator it = test_map.begin();
	std::cout << (*it).second << std::endl;
	it++;
	std::cout << (*it).second << std::endl;
	it++;
	std::cout << (*it).second << std::endl;
	it++;
	std::cout << (*it).second << std::endl;
	it++;
	std::cout << (*it).second << std::endl;
	it++;
	std::cout << (*it).second << std::endl;

	std::cout << (*it).second << std::endl;
	it--;
	std::cout << (*it).second << std::endl;
	it--;
	std::cout << (*it).second << std::endl;
	it--;
	std::cout << (*it).second << std::endl;
	it--;
	std::cout << (*it).second << std::endl;
	it--;
	std::cout << (*it).second << std::endl;
	// for (int i = 0; i < 150; i++)
	// 	test_map.erase(i);
	// test_map.erase(149);
	// test_map.erase(50);
	// test_map.erase(100);
	// test_map.erase(125);
	// std::cout << "map size is " << test_map.size() << std::endl;
	// test_map.display_tree();
	
}

int main() {
	test();
	exit(EXIT_SUCCESS);
}
