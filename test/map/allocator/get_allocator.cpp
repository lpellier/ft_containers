#include "../../../containers/map/map.hpp"
#include "../../test.hpp"

void	get_allocator() {
	NAMESPACE::map<TEST_TYPE, TEST_TYPE> test;

	NAMESPACE::pair<const TEST_TYPE, TEST_TYPE> * test_tab;
	test_tab = test.get_allocator().allocate(5);

	for (int i = 0; i < 5; i++)
		test.get_allocator().construct(&test_tab[i], NAMESPACE::make_pair(i, i));

	for (int i = 0; i < 5; i++)
		std::cout << test_tab[i].first << " " << test_tab[i].second << std::endl;

	for (int i = 0; i < 5; i++) {
		test.get_allocator().construct(&test_tab[i], NAMESPACE::make_pair(i, i));
	}

	for (int i = 0; i < 5; i++)
		test.get_allocator().destroy(&test_tab[i]);

	test.get_allocator().deallocate(test_tab, 5);
}

int main() {
	get_allocator();
	exit(EXIT_SUCCESS);
}
