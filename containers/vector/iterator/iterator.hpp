#pragma once

// #include "../../../includes/utils.hpp"
#include <cstddef>
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
template < class T >
class random_access_iterator {
public:
	typedef typename ft::iterator_traits<T>::value_type			value_type;
	typedef typename ft::iterator_traits<T>::difference_type	difference_type;
	typedef typename ft::iterator_traits<T>::pointer			pointer;
	typedef typename ft::iterator_traits<T>::reference			reference;
	typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;

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
		_ptr = src._ptr;
		return *this;
	}

	operator random_access_iterator<const value_type *>() {
		random_access_iterator<const value_type *> ret(_ptr);
		return ret;
	}

	// Comparison operators
	bool		operator== (const random_access_iterator & rhs) const {
		return _ptr == rhs._ptr;
	}
	bool		operator!= (const random_access_iterator & rhs) const {
		return _ptr != rhs._ptr;
	}
	bool		operator<  (const random_access_iterator & rhs) const {
		return _ptr < rhs._ptr;
	}
	bool		operator>  (const random_access_iterator & rhs) const {
		return _ptr > rhs._ptr;
	}
	bool		operator<= (const random_access_iterator & rhs) const {
		return _ptr <= rhs._ptr;
	}
	bool		operator>= (const random_access_iterator & rhs) const {
		return _ptr >= rhs._ptr;
	}


	reference			operator*  (void) const {
		return *(_ptr);
	}

	reference			operator[] (const int & offset) const {
		return *(_ptr + offset);
	}

	pointer				operator-> () const {
		return &(operator*());
	}

	// for non constant iterators
	void		operator*  (const reference ref) {
		*(_ptr) = ref;
	}

	random_access_iterator	&	operator++ (void) {
		_ptr++;
		return *this;
	}
	random_access_iterator		operator++ (int) {
		random_access_iterator tmp(*this);
		operator++();
		return tmp;
	}

	// friend template functions for operator + overloading because int might be before or after iterator
	random_access_iterator	operator+  (const int & rhs) const {
		random_access_iterator ret(*this);
		ret += rhs;
		return ret;
	}

	template < class U >
	friend random_access_iterator<U>	operator+  (const int & lhs, const random_access_iterator<U> & rhs);
	
	random_access_iterator &	operator-- (void) {
		_ptr--;
		return *this;
	}
	random_access_iterator		operator-- (int) {
		random_access_iterator tmp(*this);
		operator--();
		return tmp;
	}

	random_access_iterator		operator-  (const int & subbed) const {
		random_access_iterator ret(*this);
		ret._ptr -= subbed;
		return ret;
	}

	std::ptrdiff_t				operator-  (const random_access_iterator & subbed) const {
		std::ptrdiff_t ret = static_cast<std::ptrdiff_t>(_ptr - subbed._ptr);
		return ret;
	}

	random_access_iterator &	operator+= (const int & added) {
		_ptr += added;
		return *this;
	}

	random_access_iterator &	operator-= (const int & subbed) {
		_ptr -= subbed;
		return *this;
	}

	T	get_ptr() const {
		return _ptr;
	}

protected:
	T	_ptr;

};

// friend function for operator + in case of int before iterator
template < class U >
random_access_iterator<U>	operator+  (const int & lhs, const random_access_iterator<U> & rhs) {
	random_access_iterator<U> ret(rhs);
	ret += lhs;
	return ret;
}

template<typename it1, typename it2>
bool operator==(const random_access_iterator<it1>& a, const random_access_iterator<it2>& b) {return a.get_ptr() == b.get_ptr();}
template<typename it1, typename it2>
bool operator!=(const random_access_iterator<it1>& a, const random_access_iterator<it2>& b) {return a.get_ptr() != b.get_ptr();}
template<typename it1, typename it2>
bool operator<(const random_access_iterator<it1>& a, const random_access_iterator<it2>& b) {return a.get_ptr() < b.get_ptr();}
template<typename it1, typename it2>
bool operator<=(const random_access_iterator<it1>& a, const random_access_iterator<it2>& b) {return a.get_ptr() <= b.get_ptr();}
template<typename it1, typename it2>
bool operator>(const random_access_iterator<it1>& a, const random_access_iterator<it2>& b) {return a.get_ptr() > b.get_ptr();}
template<typename it1, typename it2>
bool operator>=(const random_access_iterator<it1>& a, const random_access_iterator<it2>& b) {return a.get_ptr() >= b.get_ptr();}


}
