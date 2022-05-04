#pragma once

// #include "utils.hpp"

#include <cstddef>
#include "type_traits.hpp"
#include "../containers/vector/iterator/iterator.hpp"
#include "../containers/map/iterator/iterator.hpp"

namespace ft {

/*
                                     _ _                 _             
                                    (_) |               | |            
 _ __ _____   _____ _ __ ___  ___    _| |_ ___ _ __ __ _| |_ ___  _ __ 
| '__/ _ \ \ / / _ \ '__/ __|/ _ \  | | __/ _ \ '__/ _` | __/ _ \| '__|
| | |  __/\ V /  __/ |  \__ \  __/  | | ||  __/ | | (_| | || (_) | |   
|_|  \___| \_/ \___|_|  |___/\___|  |_|\__\___|_|  \__,_|\__\___/|_|   
*/

template < class Iter >
class reverse_iterator_wrap {
protected:
	Iter	current;

public:
	typedef Iter												iterator_type;
	typedef	typename ft::iterator_traits<Iter>::difference_type		difference_type;
	typedef	typename ft::iterator_traits<Iter>::value_type			value_type;
	typedef	typename ft::iterator_traits<Iter>::pointer				pointer;
	typedef	typename ft::iterator_traits<Iter>::reference			reference;
	typedef	typename ft::iterator_traits<Iter>::iterator_category	iterator_category;

	typedef const value_type *	const_iterator_type;

	reverse_iterator_wrap (void) {} // default
	explicit reverse_iterator_wrap (iterator_type x) { // initialization
		current = x;
	}
	reverse_iterator_wrap (const reverse_iterator_wrap<Iter> & src) { // copy
		current = src.current;
	}

	reverse_iterator_wrap & operator= (const reverse_iterator_wrap<Iter> & src) { // assignment operator
		current = src.current;
		return *this;
	}

	operator reverse_iterator_wrap<random_access_iterator<const value_type *> >() {
		return reverse_iterator_wrap<random_access_iterator<const value_type *> >(current);
	}

	operator reverse_iterator_wrap<bidirectional_iterator<const value_type> >() {
		bidirectional_iterator<const value_type> ret(current);
		return reverse_iterator_wrap<bidirectional_iterator<const value_type> >(ret);
	}
	
	// Returns a copy of the underlying iterator
	iterator_type base () const {
		return current;
	}

	// Returns a reference to the element pointed to by the iterator
	reference operator* () const {
		return *(current - 1);
	}

	// Returns a pointer to the element pointed to by the iterator
	pointer operator-> () const {
		return &(operator*());
	}

	reference operator[] (difference_type n) const {
		return base()[-n - 1];
	}

	reverse_iterator_wrap & operator++ () {
		current--;
		return *this;
	}

	reverse_iterator_wrap operator++(int) {
		reverse_iterator_wrap tmp(*this);
		operator++();
		return tmp;
	}

	reverse_iterator_wrap & operator-- () {
		current++;
		return *this;
	}

	reverse_iterator_wrap operator--(int) {
		reverse_iterator_wrap tmp(*this);
		operator--();
		return tmp;
	}

	// Returns a reverse iterator pointing to the element located a n positions away from the
	// element the iterator currently points to
	// This function requires the base operator to be a random-access iterator
	reverse_iterator_wrap				operator+  (difference_type n) const {
		reverse_iterator_wrap ret(current);
		ret.current -= n;

		return ret;
	}
	template < class It >
	friend reverse_iterator_wrap<It>		operator+  (typename reverse_iterator_wrap<It>::difference_type n, const reverse_iterator_wrap<It> & it);

	// Returns a reverse iterator pointing to the element located n positions before the element the
	// iterator currently points to
	reverse_iterator_wrap				operator-  (difference_type n) const {
		reverse_iterator_wrap ret (current);
		ret.current += n;

		return ret;
	}
	template < class It >
	friend typename reverse_iterator_wrap<Iter>::difference_type operator-  (const reverse_iterator_wrap<Iter> & lhs, const reverse_iterator_wrap<Iter> & rhs);

	// Advances the reverse_iterator_wrap by n element positions
	// Requires the base iterator to be a random access iterator
	reverse_iterator_wrap &				operator+= (difference_type n) {
		current -= n;
		return *this;
	}

	// Decreases the reverse_iterator_wrap by n element positions
	// Requires the base iterator to be a random access iterator
	reverse_iterator_wrap &				operator-= (difference_type n) {
		current += n;
		return *this;
	}

	template < class Iter2 >
	bool	operator== (const reverse_iterator_wrap<Iter2> & rhs) const {
		return (base() == rhs.base());
	}

	template < class Iter2 >
	bool	operator!= (const reverse_iterator_wrap<Iter2> & rhs) const {
		return (base() != rhs.base());
	}

	template < class Iter2 >
	bool	operator<  (const reverse_iterator_wrap<Iter2> & rhs) const {
		return (base() < rhs.base());
	}

	template < class Iter2 >
	bool	operator<= (const reverse_iterator_wrap<Iter2> & rhs) const {
		return (base() <= rhs.base());
	}

	template < class Iter2 >
	bool	operator>  (const reverse_iterator_wrap<Iter2> & rhs) const {
		return (base() > rhs.base());
	}

	template < class Iter2 >
	bool	operator>= (const reverse_iterator_wrap<Iter2> & rhs) const {
		return (base() >= rhs.base());
	}

};

template < class Iter >
reverse_iterator_wrap<Iter> operator+  (typename reverse_iterator_wrap<Iter>::difference_type n, const reverse_iterator_wrap<Iter> & rev_it) {
	reverse_iterator_wrap<Iter> ret(rev_it);
	return ret + n;
}

template < class Iter >
typename reverse_iterator_wrap<Iter>::difference_type operator-  (const reverse_iterator_wrap<Iter> & lhs, const reverse_iterator_wrap<Iter> & rhs) {
	return (rhs.base() - lhs.base());
}

// template<typename Iter>
// bool operator==(const reverse_iterator_wrap<Iter>& a, const reverse_iterator_wrap<Iter>& b) {return a.base() == b.base();}
// template<typename Iter>
// bool operator!=(const reverse_iterator_wrap<Iter>& a, const reverse_iterator_wrap<Iter>& b) {return a.base() != b.base();}
// template<typename Iter>
// bool operator<(const reverse_iterator_wrap<Iter>& a, const reverse_iterator_wrap<Iter>& b) {return a.base() < b.base();}
// template<typename Iter>
// bool operator<=(const reverse_iterator_wrap<Iter>& a, const reverse_iterator_wrap<Iter>& b) {return a.base() <= b.base();}
// template<typename Iter>
// bool operator>(const reverse_iterator_wrap<Iter>& a, const reverse_iterator_wrap<Iter>& b) {return a.base() > b.base();}
// template<typename Iter>
// bool operator>=(const reverse_iterator_wrap<Iter>& a, const reverse_iterator_wrap<Iter>& b) {return a.base() >= b.base();}

}
