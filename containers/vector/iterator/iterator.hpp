#pragma once

#include "../../../includes/utils.hpp"

namespace ft {

/*
 _ _                 _             
(_) |               | |            
 _| |_ ___ _ __ __ _| |_ ___  _ __ 
| | __/ _ \ '__/ _` | __/ _ \| '__|
| | ||  __/ | | (_| | || (_) | |   
|_|\__\___|_|  \__,_|\__\___/|_|   
*/

template <	class Category, 
			class T, 
			class Distance = std::ptrdiff_t, 
			class Pointer = T*, 
			class Reference = T& >
struct iterator {
	public:
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef	Reference	reference;
		typedef Category	iterator_category;
};

/*
                     _                                                   _ _                 _             
                    | |                                                 (_) |               | |            
 _ __ __ _ _ __   __| | ___  _ __ ___      __ _  ___ ___ ___  ___ ___    _| |_ ___ _ __ __ _| |_ ___  _ __ 
| '__/ _` | '_ \ / _` |/ _ \| '_ ` _ \    / _` |/ __/ __/ _ \/ __/ __|  | | __/ _ \ '__/ _` | __/ _ \| '__|
| | | (_| | | | | (_| | (_) | | | | | |  | (_| | (_| (_|  __/\__ \__ \  | | ||  __/ | | (_| | || (_) | |   
|_|  \__,_|_| |_|\__,_|\___/|_| |_| |_|   \__,_|\___\___\___||___/___/  |_|\__\___|_|  \__,_|\__\___/|_|   
*/

// Here T is a pointer on value_type
template < typename T >
class random_access_iterator {
public:
	typedef typename iterator_traits<T>::value_type			value_type;
	typedef typename iterator_traits<T>::difference_type	difference_type;
	typedef typename iterator_traits<T>::pointer			pointer;
	typedef typename iterator_traits<T>::reference			reference;
	typedef typename iterator_traits<T>::iterator_category	iterator_category;

	// default constructor
	random_access_iterator (void) : _ptr(NULL) {}
	// parametric constructor
	random_access_iterator (pointer new_ptr) : _ptr(new_ptr) {}
	// destructor
	~random_access_iterator (void) {}
	// copy constructor
	random_access_iterator (const random_access_iterator & src) : _ptr(src._ptr) {}
	// assignment operator
	random_access_iterator & operator= (const random_access_iterator & src) {
		this->_ptr = src._ptr;
		return *this;
	}

	operator const random_access_iterator<const value_type *>() {
		return (random_access_iterator<const value_type *>(const_cast<const T>(_ptr)));
	}
	
	// Comparison operators
	bool		operator== (const random_access_iterator & rhs) const {
		return this->_ptr == rhs._ptr;
	}
	bool		operator!= (const random_access_iterator & rhs) const {
		return this->_ptr != rhs._ptr;
	}
	bool		operator<  (const random_access_iterator & rhs) const {
		return this->_ptr < rhs._ptr;
	}
	bool		operator>  (const random_access_iterator & rhs) const {
		return this->_ptr > rhs._ptr;
	}
	bool		operator<= (const random_access_iterator & rhs) const {
		return this->_ptr <= rhs._ptr;
	}
	bool		operator>= (const random_access_iterator & rhs) const {
		return this->_ptr >= rhs._ptr;
	}


	reference			operator*  (void) const {
		return *(this->_ptr);
	}

	reference			operator[] (const int & offset) const {
		return *(this->_ptr + offset);
	}

	pointer				operator-> () const {
		return &(this->operator*());
	}

	// for non constant iterators
	void		operator*  (const reference ref) {
		*(this->_ptr) = ref;
	}

	random_access_iterator	&	operator++ (void) {
		this->_ptr++;
		return *this;
	}
	random_access_iterator		operator++ (int) {
		random_access_iterator tmp(*this);
		this->operator++();
		return tmp;
	}

	// friend template functions for operator + overloading because int might be before or after iterator
	random_access_iterator	operator+  (const int & rhs) const {
		random_access_iterator ret(*this);
		ret += rhs;
		return ret;
	}

	template < typename U >
	friend random_access_iterator<U>	operator+  (const int & lhs, const random_access_iterator<U> & rhs);
	
	random_access_iterator &	operator-- (void) {
		this->_ptr--;
		return *this;
	}
	random_access_iterator		operator-- (int) {
		random_access_iterator tmp(*this);
		this->operator--();
		return tmp;
	}

	random_access_iterator		operator-  (const int & subbed) const {
		random_access_iterator ret(*this);
		ret._ptr -= subbed;
		return ret;
	}

	std::ptrdiff_t				operator-  (const random_access_iterator & subbed) const {
		std::ptrdiff_t ret = static_cast<std::ptrdiff_t>(this->_ptr - subbed._ptr);
		return ret;
	}

	random_access_iterator &	operator+= (const int & added) {
		this->_ptr += added;
		return *this;
	}

	random_access_iterator &	operator-= (const int & subbed) {
		this->_ptr -= subbed;
		return *this;
	}

protected:
	T	_ptr;

};

// friend function for operator + in case of int before iterator
template < typename U >
random_access_iterator<U>	operator+  (const int & lhs, const random_access_iterator<U> & rhs) {
	random_access_iterator<U> ret(rhs);
	ret += lhs;
	return ret;
}

/*
                                     _ _                 _             
                                    (_) |               | |            
 _ __ _____   _____ _ __ ___  ___    _| |_ ___ _ __ __ _| |_ ___  _ __ 
| '__/ _ \ \ / / _ \ '__/ __|/ _ \  | | __/ _ \ '__/ _` | __/ _ \| '__|
| | |  __/\ V /  __/ |  \__ \  __/  | | ||  __/ | | (_| | || (_) | |   
|_|  \___| \_/ \___|_|  |___/\___|  |_|\__\___|_|  \__,_|\__\___/|_|   
*/

template < typename Iter >
class random_access_reverse_iterator {
protected:
	Iter	_iter;

public:
	typedef Iter												iterator_type;
	typedef	typename iterator_traits<Iter>::difference_type		difference_type;
	typedef	typename iterator_traits<Iter>::value_type			value_type;
	typedef	typename iterator_traits<Iter>::pointer				pointer;
	typedef	typename iterator_traits<Iter>::reference			reference;
	typedef	typename iterator_traits<Iter>::iterator_category	iterator_category;

	random_access_reverse_iterator (void) { // default
		this->_iter = value_type();
	}
	explicit random_access_reverse_iterator (iterator_type x) { // initialization
		this->_iter = x;
	}
	random_access_reverse_iterator (const random_access_reverse_iterator<Iter> & src) { // copy
		this->_iter = src._iter;
	}

	random_access_reverse_iterator & operator= (const random_access_reverse_iterator<Iter> & src) { // assignment operator
		this->_iter = src._iter;
		return *this;
	}

	operator const random_access_reverse_iterator<Iter>() {
		return (random_access_reverse_iterator<Iter>(const_cast<const Iter>(_iter)));
	}
	
	// Returns a copy of the underlying iterator
	iterator_type base () const {
		return this->_iter;
	}

	// Returns a reference to the element pointed to by the iterator
	reference operator* () const {
		return *(this->_iter - 1);
	}

	// Returns a pointer to the element pointed to by the iterator
	pointer operator-> () const {
		return &(this->operator*());
	}

	reference operator[] (difference_type n) const {
		return this->base()[-n - 1];
	}

	random_access_reverse_iterator & operator++ () {
		this->_iter--;
	}

	random_access_reverse_iterator operator++(int) {
		--this->_iter;
	}

	random_access_reverse_iterator & operator-- () {
		this->_iter++;
	}

	random_access_reverse_iterator operator--(int) {
		++this->_iter;
	}

	// Returns a reverse iterator pointing to the element located a n positions away from the
	// element the iterator currently points to
	// This function requires the base operator to be a random-access iterator
	random_access_reverse_iterator				operator+  (difference_type n) const {
		random_access_reverse_iterator ret(this->_iter);
		ret._iter -= n;

		return ret;
	}
	template < typename It >
	friend random_access_reverse_iterator<It>		operator+  (typename random_access_reverse_iterator<It>::difference_type n, const random_access_reverse_iterator<It> & it);

	// Returns a reverse iterator pointing to the element located n positions before the element the
	// iterator currently points to
	random_access_reverse_iterator				operator-  (difference_type n) const {
		random_access_reverse_iterator ret (this->_iter);
		ret._iter += n;

		return ret;
	}
	friend typename random_access_reverse_iterator<Iter>::difference_type operator-  (const random_access_reverse_iterator<Iter> & lhs, const random_access_reverse_iterator<Iter> & rhs);

	// Advances the random_access_reverse_iterator by n element positions
	// Requires the base iterator to be a random access iterator
	random_access_reverse_iterator &				operator+= (difference_type n) {
		this->_iter -= n;
		return *this;
	}

	// Decreases the random_access_reverse_iterator by n element positions
	// Requires the base iterator to be a random access iterator
	random_access_reverse_iterator &				operator-= (difference_type n) {
		this->_iter += n;
		return *this;
	}

	template < typename Iter2 >
	bool	operator== (const random_access_reverse_iterator<Iter2> & rhs) const {
		return (this->base() == rhs.base());
	}

	template < typename Iter2 >
	bool	operator!= (const random_access_reverse_iterator<Iter2> & rhs) const {
		return (this->base() != rhs.base());
	}

	template < typename Iter2 >
	bool	operator<  (const random_access_reverse_iterator<Iter2> & rhs) const {
		return (this->base() < rhs.base());
	}

	template < typename Iter2 >
	bool	operator<= (const random_access_reverse_iterator<Iter2> & rhs) const {
		return (this->base() <= rhs.base());
	}

	template < typename Iter2 >
	bool	operator>  (const random_access_reverse_iterator<Iter2> & rhs) const {
		return (this->base() > rhs.base());
	}

	template < typename Iter2 >
	bool	operator>= (const random_access_reverse_iterator<Iter2> & rhs) const {
		return (this->base() >= rhs.base());
	}

};

template < typename Iter >
random_access_reverse_iterator<Iter> operator+  (typename random_access_reverse_iterator<Iter>::difference_type n, const random_access_reverse_iterator<Iter> & rev_it) {
	random_access_reverse_iterator<Iter> ret(rev_it);
	return ret + n;
}

template < typename Iter >
typename random_access_reverse_iterator<Iter>::difference_type operator-  (const random_access_reverse_iterator<Iter> & lhs, const random_access_reverse_iterator<Iter> & rhs) {
	return (rhs.base() - lhs.base());
}

}
