#include "test.hpp"

/* template for iterator test functions
template <typename Iter>
void	testDereference(Iter it, bool mine) {
	std::cout << RED;
	if (mine)
		std::cout << CYAN;
	
	// do stuff
	
	std::cout << RESET;
}
*/

template <typename Iter>
void	testItIncrement(Iter it, bool mine) {
	std::cout << RED;
	if (mine)
		std::cout << CYAN;
	
	std::cout << "iter = begin : " << *it << std::endl;
	++it;
	it++;
	*it++;
	std::cout << "++iter ; iter++ ; *iter++ : " << *it << std::endl;
	
	std::cout << RESET;
}

template <typename Iter>
void	testItDecrement(Iter it, bool mine) {
	std::cout << RED;
	if (mine)
		std::cout << CYAN;
	
	std::cout << "iter = begin : " << *it << std::endl;
	--it;
	it--;
	std::cout << "--iter ; iter-- : " << *it << std::endl;
	
	std::cout << RESET;
}

template <typename Iter>
void	testItDereference(Iter it, bool mine) {
	std::cout << RED;
	if (mine)
		std::cout << CYAN;

	std::cout << "iter = begin : " << *it << std::endl;
	*it = 16;
	std::cout << "*iter = 16 : " <<  *it << std::endl;
	*it = 0;
	std::cout << "*iter = 0 : " <<  *it << std::endl;
	
	std::cout << RESET;
}

template <typename Iter>
void	testItLoop(Iter from, Iter until, bool mine) {
	std::cout << RED;
	if (mine)
		std::cout << CYAN;
	
	std::cout << "iter :";
	while (from != until) {
		std::cout << *from << " ";
		++from;
	}
	std::cout << std::endl;
	
	std::cout << RESET;
}

template <typename Iter>
void	testItArithmetic(Iter it, bool mine) {
	std::cout << RED;
	if (mine)
		std::cout << CYAN;

	typename ft::iterator_traits<Iter>::difference_type n = 5;
	
	std::cout << "iter = begin : " << *it << std::endl;
	it = n + it + 2;
	std::cout << "iter + 5 + 2 : " << *it << std::endl;
	n = 3;
	it = it - n - 1;
	std::cout << "iter - 3 - 1 : " << *it << std::endl;
	
	std::cout << RESET;
}

template <typename Iter>
void	testItSubstractIt(Iter it, bool mine) {
	std::cout << RED;
	if (mine)
		std::cout << CYAN;
	
	Iter rhs = it + 3;
	std::cout << *rhs << " - " << *it << " : ";
	typename ft::iterator_traits<Iter>::difference_type diff = rhs - it;
	std::cout << diff << std::endl;
	
	std::cout << RESET;
}

template <typename Iter>
void	testItComparison(Iter it, bool mine) {
	std::cout << RED;
	if (mine)
		std::cout << CYAN;
	
	Iter rhs = it + 3;
	std::cout << *rhs << " < " << *it << " : " << (rhs < it) << std::endl;
	std::cout << *rhs << " > " << *it << " : " << (rhs > it) << std::endl;
	std::cout << *rhs << " <= " << *it << " : " << (rhs <= it) << std::endl;
	std::cout << *rhs << " >= " << *it << " : " << (rhs >= it) << std::endl;
	
	std::cout << RESET;
}

template <typename Iter>
void	testItCompoundAssignment(Iter it, bool mine) {
	std::cout << RED;
	if (mine)
		std::cout << CYAN;

	typename ft::iterator_traits<Iter>::difference_type n = 5;
	
	std::cout << "iter = begin : " << *it << std::endl;
	it += n;
	std::cout << "iter += 5 : " << *it << std::endl;
	n = 3;
	it -= n;
	std::cout << "iter -= 3 : " << *it << std::endl;
	
	std::cout << RESET;
}

template <typename Iter>
void	testItOffsetDereference(Iter it, bool mine) {
	std::cout << RED;
	if (mine)
		std::cout << CYAN;

	std::cout << "iter = begin : " << *it << std::endl;
	std::cout << "iter[5] : " << it[5] << std::endl;
	std::cout << "iter [3] : " << it[3] << std::endl;
	
	std::cout << RESET;
}

void	testIterator(std::vector<int> & actual_vector, ft::vector<int> & my_vector) {
	std::vector<int>::iterator act_begin_it = actual_vector.begin();
	ft::vector<int>::iterator my_begin_it = my_vector.begin();

	std::vector<int>::iterator act_end_it = actual_vector.end();
	ft::vector<int>::iterator my_end_it = my_vector.end();

	{
		std::cout << RESET << "Default constructible test" << std::endl;
		
		std::vector<int>::iterator act_default_it;
		ft::vector<int>::iterator my_default_it;
		// this segfaults if uncommented (normal behaviour)
		// std::cout << RED << *act_default_it << " " << CYAN << *my_default_it << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << RESET << "Copy constructible test" << std::endl;
		
		std::vector<int>::iterator act_copy_it(act_begin_it);
		ft::vector<int>::iterator my_copy_it(my_begin_it);
		std::cout << RED << *act_copy_it << " " << CYAN << *my_copy_it << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << RESET << "Copy assignable test" << std::endl;
		
		std::vector<int>::iterator act_copy_it = act_begin_it;
		ft::vector<int>::iterator my_copy_it = my_begin_it;
		std::cout << RED << *act_copy_it << " " << CYAN << *my_copy_it << std::endl;
		std::cout << std::endl;	
	}

	{
		std::cout << RESET << "Destructible test" << std::endl;
		
		std::vector<int>::iterator act_destruc_it;
		ft::vector<int>::iterator my_destruc_it;
		std::cout << std::endl;
	}

	{
		std::vector<int>::iterator act_cur_it(act_begin_it);
		ft::vector<int>::iterator my_cur_it(my_begin_it);

		std::cout << RESET << "Comparison == and != test and dereference test using *" << std::endl;
		std::cout << RESET << "Simple loop through vector of size 10" << std::endl;
		testItLoop(act_cur_it, act_end_it, false);
		std::cout << std::endl;
		testItLoop(my_cur_it, my_end_it, true);
		std::cout << std::endl;

		std::cout << RESET << "Dereference test as an lvalue using * (for non constant iterators)" << std::endl;
		testItDereference(act_cur_it, false);
		std::cout << std::endl;
		testItDereference(my_cur_it, true);
		std::cout << std::endl;

		std::cout << RESET << "Post/pre in/decrementation test" << std::endl;
		testItIncrement(act_cur_it, false);
		testItDecrement(act_cur_it + 2, false);
		std::cout << std::endl;
		testItIncrement(my_cur_it, true);
		testItDecrement(act_cur_it + 2, true);
		std::cout << std::endl;

		std::cout << RESET << "Arithmetic operators test" << std::endl;
		testItArithmetic(act_cur_it, false);
		testItSubstractIt(act_cur_it, false);
		std::cout << std::endl;
		testItArithmetic(my_cur_it, true);
		testItSubstractIt(my_cur_it, true);
		std::cout << std::endl;

		std::cout << RESET << "Comparison test" << std::endl;
		testItComparison(act_cur_it, false);
		std::cout << std::endl;
		testItComparison(my_cur_it, true);
		std::cout << std::endl;

		std::cout << RESET << "Compound assignment operations test" << std::endl;
		testItCompoundAssignment(act_cur_it, false);
		std::cout << std::endl;
		testItCompoundAssignment(my_cur_it, true);
		std::cout << std::endl;

		std::cout << RESET << "Offset dereference operator test" << std::endl;
		testItOffsetDereference(act_cur_it, false);
		std::cout << std::endl;
		testItOffsetDereference(my_cur_it, true);
		std::cout << std::endl;
	}
}

void	testIterator(const std::vector<int> & actual_vector, const ft::vector<int> & my_vector) {
	std::vector<int>::const_iterator act_begin_it = actual_vector.begin();
	ft::vector<int>::const_iterator my_begin_it = my_vector.begin();

	std::vector<int>::const_iterator act_end_it = actual_vector.end();
	ft::vector<int>::const_iterator my_end_it = my_vector.end();

	{
		std::cout << RESET << "Default constructible test" << std::endl;
		
		std::vector<int>::const_iterator act_default_it;
		ft::vector<int>::const_iterator my_default_it;
		// this segfaults if uncommented (normal behaviour)
		// std::cout << RED << *act_default_it << " " << CYAN << *my_default_it << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << RESET << "Copy constructible test" << std::endl;
		
		std::vector<int>::const_iterator act_copy_it(act_begin_it);
		ft::vector<int>::const_iterator my_copy_it(my_begin_it);
		std::cout << RED << *act_copy_it << " " << CYAN << *my_copy_it << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << RESET << "Copy assignable test" << std::endl;
		
		std::vector<int>::const_iterator act_copy_it(act_begin_it);
		ft::vector<int>::const_iterator my_copy_it = my_begin_it;
		std::cout << RED << *act_copy_it << " " << CYAN << *my_copy_it << std::endl;
		std::cout << std::endl;	
	}

	{
		std::cout << RESET << "Destructible test" << std::endl;
		
		std::vector<int>::const_iterator act_destruc_it;
		ft::vector<int>::const_iterator my_destruc_it;
		std::cout << std::endl;
	}

	{
		std::vector<int>::const_iterator act_cur_it(act_begin_it);
		ft::vector<int>::const_iterator my_cur_it(my_begin_it);

		std::cout << RESET << "Comparison == and != test and dereference test using *" << std::endl;
		std::cout << RESET << "Simple loop through vector of size 10" << std::endl;
		testItLoop(act_cur_it, act_end_it, false);
		std::cout << std::endl;
		testItLoop(my_cur_it, my_end_it, true);
		std::cout << std::endl;

		// std::cout << RESET << "Dereference test as an lvalue using * (for non constant iterators)" << std::endl;
		// testItDereference(act_cur_it, false);
		// std::cout << std::endl;
		// testItDereference(my_cur_it, true);
		// std::cout << std::endl;

		std::cout << RESET << "Post/pre in/decrementation test" << std::endl;
		testItIncrement(act_cur_it, false);
		testItDecrement(act_cur_it + 2, false);
		std::cout << std::endl;
		testItIncrement(my_cur_it, true);
		testItDecrement(act_cur_it + 2, true);
		std::cout << std::endl;

		std::cout << RESET << "Arithmetic operators test" << std::endl;
		testItArithmetic(act_cur_it, false);
		testItSubstractIt(act_cur_it, false);
		std::cout << std::endl;
		testItArithmetic(my_cur_it, true);
		testItSubstractIt(my_cur_it, true);
		std::cout << std::endl;

		std::cout << RESET << "Comparison test" << std::endl;
		testItComparison(act_cur_it, false);
		std::cout << std::endl;
		testItComparison(my_cur_it, true);
		std::cout << std::endl;

		std::cout << RESET << "Compound assignment operations test" << std::endl;
		testItCompoundAssignment(act_cur_it, false);
		std::cout << std::endl;
		testItCompoundAssignment(my_cur_it, true);
		std::cout << std::endl;

		std::cout << RESET << "Offset dereference operator test" << std::endl;
		testItOffsetDereference(act_cur_it, false);
		std::cout << std::endl;
		testItOffsetDereference(my_cur_it, true);
		std::cout << std::endl;
	}

}

void	testReverseIterator(std::vector<int> & actual_vector, ft::vector<int> & my_vector) {
	std::vector<int>::reverse_iterator act_rit(actual_vector.rbegin());
	ft::vector<int>::reverse_iterator my_rit(my_vector.rbegin());

	std::cout << *act_rit << " " << *my_rit << std::endl;
}
