#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "utils.hpp"

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
											                                                                                                 

template < typename T >
class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T> {
protected:
	T *	ptr;

public:
	// default constructor
	random_access_iterator (void) : ptr(nullptr) {}
	// parametric constructor
	random_access_iterator (T * new_ptr) : ptr(new_ptr) {}
	// destructor
	~random_access_iterator (void) {}
	// copy constructor
	random_access_iterator (random_access_iterator const & src) : ptr(src.ptr) {}
	// assignment operator
	random_access_iterator & operator= (random_access_iterator const & src) {
		this->ptr = src.ptr;
		return *this;
	}

	// Comparison operators
	bool		operator== (const random_access_iterator & rhs) const {
		return this->ptr == rhs.ptr;
	}
	bool		operator!= (const random_access_iterator & rhs) const {
		return this->ptr != rhs.ptr;
	}
	bool		operator<  (const random_access_iterator & rhs) const {
		return this->ptr < rhs.ptr;
	}
	bool		operator>  (const random_access_iterator & rhs) const {
		return this->ptr > rhs.ptr;
	}
	bool		operator<= (const random_access_iterator & rhs) const {
		return this->ptr <= rhs.ptr;
	}
	bool		operator>= (const random_access_iterator & rhs) const {
		return this->ptr >= rhs.ptr;
	}


	T &			operator*  (void) const {
		return *(this->ptr);
	}

	T &			operator[] (const int & offset) const {
		return *(this->ptr + offset);
	}

	T *			operator-> () const {
		return this->ptr; // might be &this->ptr
	}

	// for non constant iterators
	void		operator*  (const T & ref) {
		*(this->ptr) = ref;
	}

	random_access_iterator	&	operator++ (void) {
		this->ptr++;
		return *this;
	}
	random_access_iterator		operator++ (int) {
		random_access_iterator tmp(*this);
		this->operator++();
		return tmp;
	}

	// friend template functions for operator + overloading because int might be before or after iterator
	random_access_iterator	operator+  (const int & rhs) {
		random_access_iterator ret(*this);
		ret += rhs;
		return ret;
	}

	template < typename U >
	friend random_access_iterator<U>	operator+  (const int & lhs, const random_access_iterator<U> & rhs);
	
	random_access_iterator &	operator-- (void) {
		this->ptr--;
		return *this;
	}
	random_access_iterator		operator-- (int) {
		random_access_iterator tmp(*this);
		this->operator--();
		return tmp;
	}

	random_access_iterator		operator-  (const int & subbed) {
		random_access_iterator ret(*this);
		ret.ptr -= subbed;
		return ret;
	}

	std::ptrdiff_t				operator-  (const random_access_iterator & subbed) const {
		std::ptrdiff_t ret = static_cast<std::ptrdiff_t>(this->ptr - subbed.ptr);
		return ret;
	}

	random_access_iterator &	operator+= (const int & added) {
		this->ptr += added;
		return *this;
	}

	random_access_iterator &	operator-= (const int & subbed) {
		this->ptr -= subbed;
		return *this;
	}
};

// friend function for operator + in case of int before iterator
template < typename U >
random_access_iterator<U>	operator+  (const int & lhs, const random_access_iterator<U> & rhs) {
	random_access_iterator<U> ret(rhs);
	ret += lhs;
	return ret;
}

/*
                     _                                                                       _      _ _                 _             
                    | |                                                                     | |    (_) |               | |            
 _ __ __ _ _ __   __| | ___  _ __ ___      __ _  ___ ___ ___  ___ ___     ___ ___  _ __  ___| |_    _| |_ ___ _ __ __ _| |_ ___  _ __ 
| '__/ _` | '_ \ / _` |/ _ \| '_ ` _ \    / _` |/ __/ __/ _ \/ __/ __|   / __/ _ \| '_ \/ __| __|  | | __/ _ \ '__/ _` | __/ _ \| '__|
| | | (_| | | | | (_| | (_) | | | | | |  | (_| | (_| (_|  __/\__ \__ \  | (_| (_) | | | \__ \ |_   | | ||  __/ | | (_| | || (_) | |   
|_|  \__,_|_| |_|\__,_|\___/|_| |_| |_|   \__,_|\___\___\___||___/___/   \___\___/|_| |_|___/\__|  |_|\__\___|_|  \__,_|\__\___/|_|   
*/

template < typename T >
class random_access_const_iterator : public ft::iterator<ft::random_access_iterator_tag, T> {
protected:
	T *	ptr;

public:
	// default constructor
	random_access_const_iterator (void) : ptr(nullptr) {}
	// parametric constructor
	random_access_const_iterator (T * new_ptr) : ptr(new_ptr) {}
	// destructor
	~random_access_const_iterator (void) {}
	// copy constructor
	random_access_const_iterator (const random_access_const_iterator & src) : ptr(src.ptr) {}
	// assignment operator
	random_access_const_iterator & operator= (const random_access_const_iterator & src) {
		this->ptr = src.ptr;
		return *this;
	}

	// Comparison operators
	bool		operator== (const random_access_const_iterator & rhs) const {
		return this->ptr == rhs.ptr;
	}
	bool		operator!= (const random_access_const_iterator & rhs) const {
		return this->ptr != rhs.ptr;
	}
	bool		operator<  (const random_access_const_iterator & rhs) const {
		return this->ptr < rhs.ptr;
	}
	bool		operator>  (const random_access_const_iterator & rhs) const {
		return this->ptr > rhs.ptr;
	}
	bool		operator<= (const random_access_const_iterator & rhs) const {
		return this->ptr <= rhs.ptr;
	}
	bool		operator>= (const random_access_const_iterator & rhs) const {
		return this->ptr >= rhs.ptr;
	}


	const T &			operator*  (void) const {
		return *(this->ptr);
	}

	const T &			operator[] (const int & offset) const {
		return *(this->ptr + offset);
	}

	const T *			operator-> () const {
		return this->ptr; // might be &this->ptr
	}

	// for non constant iterators
	void				operator*  (const T & ref) {
		return ;
	}

	random_access_const_iterator &		operator++ (void) {
		this->ptr++;
		return *this;
	}
	random_access_const_iterator		operator++ (int) {
		random_access_const_iterator tmp(*this);
		this->operator++();
		return tmp;
	}

	random_access_const_iterator	operator+  (const int & rhs) {
		random_access_const_iterator	ret(*this);
		ret += rhs;
		return ret;
	}

	// friend template functions for operator + overloading because int might be before iterator
	template < typename U >
	friend random_access_const_iterator<U>	operator+  (const int & lhs, const random_access_const_iterator<U> & rhs);

	random_access_const_iterator &		operator-- (void) {
		this->ptr--;
		return *this;
	}
	random_access_const_iterator 		operator-- (int) {
		random_access_const_iterator tmp(*this);
		this->operator--();
		return tmp;
	}

	random_access_const_iterator		operator-  (const int & subbed) {
		random_access_const_iterator ret(*this);
		ret.ptr -= subbed;
		return ret;
	}

	typename random_access_const_iterator<T>::difference_type						operator-  (const random_access_const_iterator & subbed) const {
		std::ptrdiff_t ret = static_cast<std::ptrdiff_t>(this->ptr - subbed.ptr);
		return ret;
	}

	random_access_const_iterator &		operator+= (const int & added) {
		this->ptr += added;
		return *this;
	}

	random_access_const_iterator &		operator-= (const int & subbed) {
		this->ptr -= subbed;
		return *this;
	}
};

// friend function for operator + in case of int before iterator
template < typename U >
random_access_const_iterator<U>	operator+  (const int & lhs, const random_access_const_iterator<U> & rhs) {
	random_access_const_iterator<U> ret(rhs);
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
class reverse_iterator {
protected:
	Iter	current;

public:
	typedef Iter		iterator_type;
	typedef	typename ft::iterator_traits<Iter>::difference_type difference_type;
	typedef	typename ft::iterator_traits<Iter>::value_type value_type;
	typedef	typename ft::iterator_traits<Iter>::pointer pointer;
	typedef	typename ft::iterator_traits<Iter>::reference reference;
	typedef	typename ft::iterator_traits<Iter>::iterator_category iterator_category;

	reverse_iterator (void) {}
	
	explicit reverse_iterator (iterator_type x) {
	}

	template < typename U >
	reverse_iterator (const reverse_iterator<U> & src) {}

	template < typename U >
	reverse_iterator & operator= (const reverse_iterator<U> & src) {

	}

	iterator_type base () const {

	}

	reference operator* () const {

	}

	pointer operator-> () const {}

	reference operator[] (difference_type n) const {}

	reverse_iterator & operator++ () {}

	reverse_iterator operator++(int) {}

	reverse_iterator & operator-- () {}

	reverse_iterator operator--(int) {}

	reverse_iterator operator+  (difference_type n) const {} 

	template < typename It >
	friend reverse_iterator<It> operator+  (typename reverse_iterator<It>::difference_type n, const reverse_iterator<It> & it);

	reverse_iterator operator-  (difference_type n) const {}

	template < typename It >
	typename reverse_iterator::difference_type	operator-  (const reverse_iterator<It> & rhs) const {
		
	}

	reverse_iterator & operator+= (difference_type n) {}

	reverse_iterator & operator-= (difference_type n) {}

	template < typename Iter2 >
	bool	operator== (const reverse_iterator<Iter2> & rhs) {
		return (this->base() == rhs.base());
	}

	template < typename Iter2 >
	bool	operator!= (const reverse_iterator<Iter2> & rhs);

	template < typename Iter2 >
	bool	operator<  (const reverse_iterator<Iter2> & rhs);

	template < typename Iter2 >
	bool	operator<= (const reverse_iterator<Iter2> & rhs);

	template < typename Iter2 >
	bool	operator>  (const reverse_iterator<Iter2> & rhs);

	template < typename Iter2 >
	bool	operator>= (const reverse_iterator<Iter2> & rhs);

};

template < typename Iter >
reverse_iterator<Iter> operator+  (typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter> & it) {

}

}

#endif
