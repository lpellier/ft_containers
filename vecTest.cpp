#include "test.hpp"

template < typename Vec >
void	outputVecCapacity(Vec & vec, bool mine) {
	std::cout << RED;
	if (mine)
		std::cout << CYAN;
	
	std::cout << "size : " << vec.size() << " ; ";
	std::cout << "capacity : " << vec.capacity() << " ; ";
	std::cout << "max_size : " << vec.max_size() << std::endl;
}

template < typename Vec >
void	outputVecContents(Vec & vec, bool mine) {
	std::cout << RED;
	if (mine)
		std::cout << CYAN;
	
	for (typename Vec::iterator from = vec.begin(); from != vec.end(); from++)
		std::cout << *from << " ";
	std::cout << std::endl;
}

template < typename Vec >
void	testVecCapacity(Vec & vec, bool mine) {
	std::cout << RED;
	if (mine)
		std::cout << CYAN;
	
	std::cout << "size : " << vec.size() << " ; ";
	std::cout << "capacity : " << vec.capacity() << " ; ";
	std::cout << "max_size : " << vec.max_size() << " ; " << std::endl;
	vec.reserve(100);
	vec[10] = 1;
	std::cout << "size : " << vec.size() << " ; ";
	std::cout << "capacity : " << vec.capacity() << " ; ";
	std::cout << "max_size : " << vec.max_size() << std::endl;
}

template < typename Vec >
void	testVecInsert(Vec & vec, bool mine) {
	std::cout << RED;
	if (mine)
		std::cout << CYAN;

	Vec	vecTest(11, 5);

	// Might want to try to invalidate iterators in this one and see what happens
	std::cout << "Return of insert : " << *(vec.insert(vec.begin() + 2, 3)) << std::endl;
	outputVecContents(vec, mine);
	outputVecCapacity(vec, mine);
	vec.insert(vec.begin() + 5, 5, 42);
	outputVecContents(vec, mine);
	outputVecCapacity(vec, mine);
	vec.insert(vec.begin() + 3, vecTest.begin(), vecTest.end());
	outputVecContents(vec, mine);
	outputVecCapacity(vec, mine);
}

template < typename Vec >
void	testVecErase(Vec & vec, bool mine) {
	std::cout << RED;
	if (mine)
		std::cout << CYAN;

	// Might want to try to invalidate iterators in this one and see what happens
	std::cout << "Return of erase : " << *(vec.erase(vec.begin() + 2)) << std::endl;
	outputVecContents(vec, mine);
	outputVecCapacity(vec, mine);
	std::cout << "Return of erase : " << *(vec.erase(vec.begin() + 1, vec.begin() + 23)) << std::endl;
	outputVecContents(vec, mine);
	outputVecCapacity(vec, mine);
}

template < typename Vec >
void	testVecSwap(Vec & vec, bool mine) {
	std::cout << RED;
	if (mine)
		std::cout << CYAN;

	Vec swapTarget(10, 5);
	std::cout << "Swap target : " << std::endl;
	outputVecContents(swapTarget, mine);
	outputVecCapacity(swapTarget, mine);
	std::cout << "To be swapped : " << std::endl;
	outputVecContents(vec, mine);
	outputVecCapacity(vec, mine);
	vec.swap(swapTarget);
	std::cout << "Swap target : " << std::endl;
	outputVecContents(swapTarget, mine);
	outputVecCapacity(swapTarget, mine);
	std::cout << "To be swapped : " << std::endl;
	outputVecContents(vec, mine);
	outputVecCapacity(vec, mine);
}

template < typename Vec >
void	testVecAssign(Vec & vec, bool mine) {
	std::cout << RED;
	if (mine)
		std::cout << CYAN;

	outputVecContents(vec, mine);
	outputVecCapacity(vec, mine);
	
	Vec assignContent(18, 5);

	vec.assign(assignContent.begin(), assignContent.end());

	outputVecContents(vec, mine);
	outputVecCapacity(vec, mine);
}

template < typename Vec >
void	testVecPushback(Vec & vec, bool mine) {
	std::cout << RED;
	if (mine)
		std::cout << CYAN;

	outputVecContents(vec, mine);
	outputVecCapacity(vec, mine);
	
	for (typename Vec::size_type i = 0; i < 30; i++)
		vec.push_back(i);

	outputVecContents(vec, mine);
	outputVecCapacity(vec, mine);
}

void	testVector(std::vector<int> & act_vec, ft::vector<int> & my_vec) {
	std::cout << RESET << "Simple loop" << std::endl;
	outputVecContents(act_vec, false);
	outputVecContents(my_vec, true);
	std::cout << std::endl;

	// std::cout << RESET << "Assign tests" << std::endl;
	// testVecAssign(act_vec, false);
	// testVecAssign(my_vec, true);
	// std::cout << std::endl;

	// std::cout << RESET << "Push back tests" << std::endl;
	// testVecPushback(act_vec, false);
	// testVecPushback(my_vec, true);
	// std::cout << std::endl;

	// std::cout << RESET << "Insert tests" << std::endl;
	// testVecInsert(act_vec, false);
	// testVecInsert(my_vec, true);
	// std::cout << std::endl;

	// std::cout << RESET << "Erase tests" << std::endl;
	// testVecErase(act_vec, false);
	// testVecErase(my_vec, true);
	// std::cout << std::endl;

	// std::cout << RESET << "Swap tests" << std::endl;
	// testVecSwap(act_vec, false);
	// testVecSwap(my_vec, true);
	// std::cout << std::endl;
}
