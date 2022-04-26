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
private:
	node<T> *	_ptr;
	node<T> *	_end;
	node<T> *	_rend;

	bool	_is_rightmost_node() {
		node<T> *	tmp = _ptr;

		while (tmp && tmp->parent)
			tmp = tmp->parent;
		while (tmp && tmp->right)
			tmp = tmp->right;
		if (tmp == _ptr)
			return true;
		return false;
	}

	bool	_is_leftmost_node() {
		node<T> *	tmp = _ptr;

		while (tmp && tmp->parent)
			tmp = tmp->parent;
		while (tmp && tmp->left)
			tmp = tmp->left;
		if (tmp == _ptr)
			return true;
		return false;
	}
	

public:
	typedef typename ft::map_iterator_traits<T>::value_type			value_type;
	typedef typename ft::map_iterator_traits<T>::difference_type	difference_type;
	typedef typename ft::map_iterator_traits<T>::pointer			pointer;
	typedef typename ft::map_iterator_traits<T>::reference			reference;
	typedef typename ft::map_iterator_traits<T>::iterator_category	iterator_category;

	// default constructor 
	bidirectional_iterator (void) : _ptr(NULL) {}
	// parametric constructor 
	bidirectional_iterator (node<T> * new_ptr) : _ptr(new_ptr), _end(_ptr->_end), _rend(_ptr->_rend) {}
	// destructor
	~bidirectional_iterator (void) {}
	// copy constructor
	bidirectional_iterator (const bidirectional_iterator & src) : _ptr(src._ptr), _end(_ptr->_end), _rend(_ptr->_rend) {}
	// assignment operator
	bidirectional_iterator & operator= (const bidirectional_iterator & src) {
		_ptr = src._ptr;
		_end = _ptr->_end;
		_rend = _ptr->_rend;
		return *this;
	}
	
	operator bidirectional_iterator<const value_type>() {
		bidirectional_iterator<const value_type>	ret(reinterpret_cast<node<const T> *>(_ptr));
		return ret;
		// return bidirectional_iterator<const value_type>(reinterpret_cast<node<const T> *>(_ptr));
	}
	
	// Comparison operators
	bool		operator== (const bidirectional_iterator & rhs) const {
		return _ptr == rhs._ptr;
	}
	bool		operator!= (const bidirectional_iterator & rhs) const {
		return _ptr != rhs._ptr;
	}
	bool		operator<  (const bidirectional_iterator & rhs) const {
		return _ptr < rhs._ptr;
	}
	bool		operator>  (const bidirectional_iterator & rhs) const {
		return _ptr > rhs._ptr;
	}
	bool		operator<= (const bidirectional_iterator & rhs) const {
		return _ptr <= rhs._ptr;
	}
	bool		operator>= (const bidirectional_iterator & rhs) const {
		return _ptr >= rhs._ptr;
	}


	reference			operator*  (void) const {
		return ((*_ptr).data);
	}

	reference			operator[] (const int & offset) const {
		bidirectional_iterator tmp(_ptr);
		tmp += offset;
		return *(tmp);
	}

	pointer				operator-> () const {
		return &(operator*());
	}

	// for non constant iterators
	void		operator*  (reference ref) {
		*(_ptr)->data = ref;
	}

	bidirectional_iterator	&	operator++ (void) {
		if (_ptr == _end)
			return *this;
		if (_ptr && _ptr->right) {
			_ptr = _ptr->right;
			while (_ptr->left)
				_ptr = _ptr->left;
		}
		else if (_ptr && _is_rightmost_node()) {
			_ptr = _ptr->_end;
		}
		else if (_ptr && _ptr->parent) {
			while (_ptr && _ptr->parent && _ptr == _ptr->parent->right)
				_ptr = _ptr->parent;
			_ptr = _ptr->parent;
		}
		return *this;
	}
	bidirectional_iterator		operator++ (int) {
		bidirectional_iterator tmp(*this);
		operator++();
		return tmp;
	}

	// friend template functions for operator + overloading because int might be before or after iterator
	bidirectional_iterator	operator+  (const int & rhs) const {
		bidirectional_iterator ret(*this);
		for (int i = 0; i < rhs; i++)
			ret++;
		return ret;
	}

	template < class U >
	friend bidirectional_iterator<U>	operator+  (const int & lhs, const bidirectional_iterator<U> & rhs);
	
	bidirectional_iterator &	operator-- (void) {
		if (_ptr == _rend)
			return *this;
		if (_ptr && _ptr->left) {
			_ptr = _ptr->left;
			while (_ptr->right)
				_ptr = _ptr->right;
		}
		else if (_ptr && _is_leftmost_node()) {
			_ptr = _ptr->_rend;
		}
		else if (_ptr && _ptr->parent) {
			while (_ptr && _ptr->parent && _ptr == _ptr->parent->left)
				_ptr = _ptr->parent;
			_ptr = _ptr->parent;
		}
		return *this;
	}
	bidirectional_iterator		operator-- (int) {
		bidirectional_iterator tmp(*this);
		operator--();
		return tmp;
	}

	bidirectional_iterator		operator-  (const int & subbed) const {
		bidirectional_iterator ret(*this);
		for (int i = 0; i < subbed; i++)
			ret--;
		return ret;
	}

	std::ptrdiff_t				operator-  (const bidirectional_iterator & subbed) const {
		std::ptrdiff_t ret = static_cast<std::ptrdiff_t>(_ptr - subbed._ptr);
		return ret;
	}

	bidirectional_iterator &	operator+= (const int & added) {
		for (int i = 0; i < added; i++)
			_ptr++;
		return *this;
	}

	bidirectional_iterator &	operator-= (const int & subbed) {
		for (int i = 0; i < subbed; i++)
			_ptr--;
		return *this;
	}

	node<T> *	get_ptr() const {
		return _ptr;
	}

};

// friend function for operator + in case of int before iterator
template < class U >
bidirectional_iterator<U>	operator+  (const int & lhs, const bidirectional_iterator<U> & rhs) {
	bidirectional_iterator<U> ret(rhs);
	ret += lhs;
	return ret;
}

// template<typename it1, typename it2>
// bool operator==(const bidirectional_iterator<it1>& a, const bidirectional_iterator<it2>& b) {return a.get_ptr() == b.get_ptr();}
// template<typename it1, typename it2>
// bool operator!=(const bidirectional_iterator<it1>& a, const bidirectional_iterator<it2>& b) {return a.get_ptr() != b.get_ptr();}
// template<typename it1, typename it2>
// bool operator<(const bidirectional_iterator<it1>& a, const bidirectional_iterator<it2>& b) {return a.get_ptr() < b.get_ptr();}
// template<typename it1, typename it2>
// bool operator<=(const bidirectional_iterator<it1>& a, const bidirectional_iterator<it2>& b) {return a.get_ptr() <= b.get_ptr();}
// template<typename it1, typename it2>
// bool operator>(const bidirectional_iterator<it1>& a, const bidirectional_iterator<it2>& b) {return a.get_ptr() > b.get_ptr();}
// template<typename it1, typename it2>
// bool operator>=(const bidirectional_iterator<it1>& a, const bidirectional_iterator<it2>& b) {return a.get_ptr() >= b.get_ptr();}

}

