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

void	test() {
	srand(time(NULL));
	std::vector<ft::pair<int, int> > test_vec;
	// int saved;
	 std::vector<std::pair<int, int> > test_vec2;
	 for (int i = 0; i < 100; i++) {
	 	int random = rand() % 100 + 1;
	// 	if (i == 9)
	// 		saved = random;
	 	test_vec.push_back(ft::make_pair(random, random));
	 }
	
	//test_vec.push_back(ft::make_pair(60, 60));
	//test_vec.push_back(ft::make_pair(25, 25));
	//test_vec.push_back(ft::make_pair(68, 68));
	//test_vec.push_back(ft::make_pair(73, 73));
	//test_vec.push_back(ft::make_pair(20, 20));
	//test_vec.push_back(ft::make_pair(45, 45));
	//test_vec.push_back(ft::make_pair(7, 7));
	//test_vec.push_back(ft::make_pair(34, 34));
	//test_vec.push_back(ft::make_pair(50, 50));
	//test_vec.push_back(ft::make_pair(32, 32));

	ft::map<int, int> test(test_vec.begin(), test_vec.end());
	test.display_tree();
	// std::cout << "Deleting " << saved << " node" << std::endl;
	// test.erase(saved);
	// test.display_tree();

	// std::map<int, int> test2(test_vec2.begin(), test_vec2.end());

	// _display_tree(test2.begin(), test2.end());
}

int main() {
	test();
	exit(EXIT_SUCCESS);
}
