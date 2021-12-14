#include "../../../includes/test.hpp"

void	get_allocator() {
	CONTAINER test;

	int * test_tab;
	test_tab = test.get_allocator().allocate(5);

	for (int i = 0; i < 5; i++)
		test.get_allocator().construct(&test_tab[i], i);

	for (int i = 0; i < 5; i++)
		std::cout << test_tab[i] << std::endl;

	for (int i = 0; i < 5; i++) {
		test.get_allocator().construct(&test_tab[i], i);
	}

	for (int i = 0; i < 5; i++)
		test.get_allocator().destroy(&test_tab[i]);

	test.get_allocator().deallocate(test_tab, 5);
}

int main() {
	get_allocator();
	exit(EXIT_SUCCESS);
}
