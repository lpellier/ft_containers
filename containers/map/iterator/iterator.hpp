#pragma once

#include "../../../includes/utils.hpp"
#include "../../../includes/type_traits.hpp"

namespace ft {

/*
 _ _                 _             
(_) |               | |            
 _| |_ ___ _ __ __ _| |_ ___  _ __ 
| | __/ _ \ '__/ _` | __/ _ \| '__|
| | ||  __/ | | (_| | || (_) | |   
|_|\__\___|_|  \__,_|\__\___/|_|   
*/

// template <	class Category, 
// 			class T, 
// 			class Distance = std::ptrdiff_t, 
// 			class Pointer = T*, 
// 			class Reference = T& >
// struct iterator {
// 	public:
// 		typedef T			value_type;
// 		typedef Distance	difference_type;
// 		typedef Pointer		pointer;
// 		typedef	Reference	reference;
// 		typedef Category	iterator_category;
// };


/*
                     _                                                   _ _                 _             
                    | |                                                 (_) |               | |            
 _ __ __ _ _ __   __| | ___  _ __ ___      __ _  ___ ___ ___  ___ ___    _| |_ ___ _ __ __ _| |_ ___  _ __ 
| '__/ _` | '_ \ / _` |/ _ \| '_ ` _ \    / _` |/ __/ __/ _ \/ __/ __|  | | __/ _ \ '__/ _` | __/ _ \| '__|
| | | (_| | | | | (_| | (_) | | | | | |  | (_| | (_| (_|  __/\__ \__ \  | | ||  __/ | | (_| | || (_) | |   
|_|  \__,_|_| |_|\__,_|\___/|_| |_| |_|   \__,_|\___\___\___||___/___/  |_|\__\___|_|  \__,_|\__\___/|_|   
*/

template < class T >
class bidirectional_iterator {
protected:
	
	struct s_node<T> *	_ptr;


public:
	typedef T				value_type;
	typedef struct s_node<T> *		pointer;
	typedef T &				reference;
	typedef std::ptrdiff_t	difference_type;
	// typedef typename iterator_traits<T>::value_type			value_type;
	// typedef typename iterator_traits<T>::difference_type	difference_type;
	// typedef typename iterator_traits<T>::pointer			pointer;
	// typedef typename iterator_traits<T>::reference			reference;
	// typedef typename iterator_traits<T>::iterator_category	iterator_category;

	// default constructor
	bidirectional_iterator (void) : _ptr(NULL) {}
	// parametric constructor
	bidirectional_iterator (pointer new_ptr) : _ptr(new_ptr) {}
	// destructor
	~bidirectional_iterator (void) {}
	// copy constructor
	bidirectional_iterator (const bidirectional_iterator & src) : _ptr(src._ptr) {}
	// assignment operator
	bidirectional_iterator & operator= (const bidirectional_iterator & src) {
		this->_ptr = src._ptr;
		return *this;
	}

	// operator const bidirectional_iterator<const value_type *>() {
	// 	return (bidirectional_iterator<const value_type *>(const_cast<const T>(_ptr)));
	// }
	
	// Comparison operators
	bool		operator== (const bidirectional_iterator & rhs) const {
		return this->_ptr == rhs._ptr;
	}
	bool		operator!= (const bidirectional_iterator & rhs) const {
		return this->_ptr != rhs._ptr;
	}
	bool		operator<  (const bidirectional_iterator & rhs) const {
		return this->_ptr < rhs._ptr;
	}
	bool		operator>  (const bidirectional_iterator & rhs) const {
		return this->_ptr > rhs._ptr;
	}
	bool		operator<= (const bidirectional_iterator & rhs) const {
		return this->_ptr <= rhs._ptr;
	}
	bool		operator>= (const bidirectional_iterator & rhs) const {
		return this->_ptr >= rhs._ptr;
	}


	reference			operator*  (void) const {
		return *((*this->_ptr).data);
	}

	// reference			operator[] (const int & offset) const {
	// 	return *(this->_ptr + offset);
	// }

	pointer				operator-> () const {
		return &(this->operator*());
	}

	// for non constant iterators
	// void		operator*  (const reference ref) {
	// 	*(this->_ptr) = ref;
	// }

	bidirectional_iterator	&	operator++ (void) {
		if (_ptr && _ptr->right) {
			_ptr = _ptr->right;
			while (_ptr->left)
				_ptr = _ptr->left;
		}
		else if (_ptr && _ptr->parent) {
			_ptr = _ptr->parent;
		}
		return *this;
	}
	bidirectional_iterator		operator++ (int) {
		bidirectional_iterator tmp(*this);
		this->operator++();
		return tmp;
	}

	// friend template functions for operator + overloading because int might be before or after iterator
	bidirectional_iterator	operator+  (const int & rhs) const {
		bidirectional_iterator ret(*this);
		ret += rhs;
		return ret;
	}

	template < class U >
	friend bidirectional_iterator<U>	operator+  (const int & lhs, const bidirectional_iterator<U> & rhs);
	
	// TODO CHECK WHETHER MAP ITERATORS ARE DEREFERANCABLE BEFORE BEGIN OR AFTER END
	bidirectional_iterator &	operator-- (void) {
		if (_ptr && _ptr->left) {
			_ptr = _ptr->left;
			while (_ptr->right)
				_ptr = _ptr->right;
		}
		else if (_ptr && _ptr->parent) // ! Probably wrong
			_ptr = _ptr->parent;
		return *this;
	}
	bidirectional_iterator		operator-- (int) {
		bidirectional_iterator tmp(*this);
		this->operator--();
		return tmp;
	}

	bidirectional_iterator		operator-  (const int & subbed) const {
		bidirectional_iterator ret(*this);
		ret._ptr -= subbed;
		return ret;
	}

	std::ptrdiff_t				operator-  (const bidirectional_iterator & subbed) const {
		std::ptrdiff_t ret = static_cast<std::ptrdiff_t>(this->_ptr - subbed._ptr);
		return ret;
	}

	bidirectional_iterator &	operator+= (const int & added) {
		this->_ptr += added;
		return *this;
	}

	bidirectional_iterator &	operator-= (const int & subbed) {
		this->_ptr -= subbed;
		return *this;
	}


};

// friend function for operator + in case of int before iterator
template < class U >
bidirectional_iterator<U>	operator+  (const int & lhs, const bidirectional_iterator<U> & rhs) {
	bidirectional_iterator<U> ret(rhs);
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

// template < class Iter >
// class bidirectional_reverse_iterator {
// protected:
// 	Iter	_iter;

// public:
// 	typedef Iter												iterator_type;
// 	typedef	typename iterator_traits<Iter>::difference_type		difference_type;
// 	typedef	typename iterator_traits<Iter>::value_type			value_type;
// 	typedef	typename iterator_traits<Iter>::pointer				pointer;
// 	typedef	typename iterator_traits<Iter>::reference			reference;
// 	typedef	typename iterator_traits<Iter>::iterator_category	iterator_category;

// 	bidirectional_reverse_iterator (void) { // default
// 		this->_iter = value_type();
// 	}
// 	explicit bidirectional_reverse_iterator (iterator_type x) { // initialization
// 		this->_iter = x;
// 	}
// 	bidirectional_reverse_iterator (const bidirectional_reverse_iterator<Iter> & src) { // copy
// 		this->_iter = src._iter;
// 	}

// 	bidirectional_reverse_iterator & operator= (const bidirectional_reverse_iterator<Iter> & src) { // assignment operator
// 		this->_iter = src._iter;
// 		return *this;
// 	}

// 	// operator const bidirectional_reverse_iterator<Iter>() {
// 	// 	return (bidirectional_reverse_iterator<Iter>(const_cast<const Iter>(_iter)));
// 	// }
	
// 	// Returns a copy of the underlying iterator
// 	iterator_type base () const {
// 		return this->_iter;
// 	}

// 	// Returns a reference to the element pointed to by the iterator
// 	reference operator* () const {
// 		return *(this->_iter - 1);
// 	}

// 	// Returns a pointer to the element pointed to by the iterator
// 	pointer operator-> () const {
// 		return &(this->operator*());
// 	}

// 	reference operator[] (difference_type n) const {
// 		return this->base()[-n - 1];
// 	}

// 	bidirectional_reverse_iterator & operator++ () {
// 		this->_iter--;
// 	}

// 	bidirectional_reverse_iterator operator++(int) {
// 		--this->_iter;
// 	}

// 	bidirectional_reverse_iterator & operator-- () {
// 		this->_iter++;
// 	}

// 	bidirectional_reverse_iterator operator--(int) {
// 		++this->_iter;
// 	}

// 	// Returns a reverse iterator pointing to the element located a n positions away from the
// 	// element the iterator currently points to
// 	// This function requires the base operator to be a random-access iterator
// 	bidirectional_reverse_iterator				operator+  (difference_type n) const {
// 		bidirectional_reverse_iterator ret(this->_iter);
// 		ret._iter -= n;

// 		return ret;
// 	}
// 	template < class It >
// 	friend bidirectional_reverse_iterator<It>		operator+  (typename bidirectional_reverse_iterator<It>::difference_type n, const bidirectional_reverse_iterator<It> & it);

// 	// Returns a reverse iterator pointing to the element located n positions before the element the
// 	// iterator currently points to
// 	bidirectional_reverse_iterator				operator-  (difference_type n) const {
// 		bidirectional_reverse_iterator ret (this->_iter);
// 		ret._iter += n;

// 		return ret;
// 	}
// 	template < class It >
// 	friend typename bidirectional_reverse_iterator<Iter>::difference_type operator-  (const bidirectional_reverse_iterator<Iter> & lhs, const bidirectional_reverse_iterator<Iter> & rhs);

// 	// Advances the bidirectional_reverse_iterator by n element positions
// 	// Requires the base iterator to be a random access iterator
// 	bidirectional_reverse_iterator &				operator+= (difference_type n) {
// 		this->_iter -= n;
// 		return *this;
// 	}

// 	// Decreases the bidirectional_reverse_iterator by n element positions
// 	// Requires the base iterator to be a random access iterator
// 	bidirectional_reverse_iterator &				operator-= (difference_type n) {
// 		this->_iter += n;
// 		return *this;
// 	}

// 	template < class Iter2 >
// 	bool	operator== (const bidirectional_reverse_iterator<Iter2> & rhs) const {
// 		return (this->base() == rhs.base());
// 	}

// 	template < class Iter2 >
// 	bool	operator!= (const bidirectional_reverse_iterator<Iter2> & rhs) const {
// 		return (this->base() != rhs.base());
// 	}

// 	template < class Iter2 >
// 	bool	operator<  (const bidirectional_reverse_iterator<Iter2> & rhs) const {
// 		return (this->base() < rhs.base());
// 	}

// 	template < class Iter2 >
// 	bool	operator<= (const bidirectional_reverse_iterator<Iter2> & rhs) const {
// 		return (this->base() <= rhs.base());
// 	}

// 	template < class Iter2 >
// 	bool	operator>  (const bidirectional_reverse_iterator<Iter2> & rhs) const {
// 		return (this->base() > rhs.base());
// 	}

// 	template < class Iter2 >
// 	bool	operator>= (const bidirectional_reverse_iterator<Iter2> & rhs) const {
// 		return (this->base() >= rhs.base());
// 	}

// };

// template < class Iter >
// bidirectional_reverse_iterator<Iter> operator+  (typename bidirectional_reverse_iterator<Iter>::difference_type n, const bidirectional_reverse_iterator<Iter> & rev_it) {
// 	bidirectional_reverse_iterator<Iter> ret(rev_it);
// 	return ret + n;
// }

// template < class Iter >
// typename bidirectional_reverse_iterator<Iter>::difference_type operator-  (const bidirectional_reverse_iterator<Iter> & lhs, const bidirectional_reverse_iterator<Iter> & rhs) {
// 	return (rhs.base() - lhs.base());
// }

}
