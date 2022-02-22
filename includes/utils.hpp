#pragma once

// #include <cstddef>
// #include <functional>
// #include <memory>
#include <iostream>
#include <cstdlib>
#include "type_traits.hpp"

namespace ft {
/*
                  _     _         _  __ 
                 | |   | |       (_)/ _|
  ___ _ __   __ _| |__ | | ___    _| |_ 
 / _ \ '_ \ / _` | '_ \| |/ _ \  | |  _|
|  __/ | | | (_| | |_) | |  __/  | | |  
 \___|_| |_|\__,_|_.__/|_|\___|  |_|_|  
*/

template < bool B, class T = void >
struct enable_if {};

template < class T >
struct enable_if<true, T> { typedef T type; };

/*
     _ _     _                       
    | (_)   | |                      
  __| |_ ___| |_ __ _ _ __   ___ ___ 
 / _` | / __| __/ _` | '_ \ / __/ _ \
| (_| | \__ \ || (_| | | | | (_|  __/
 \__,_|_|___/\__\__,_|_| |_|\___\___|
*/

template < class Iter >
typename iterator_traits<Iter>::difference_type	distance(Iter from, Iter until) {
	typename iterator_traits<Iter>::difference_type ret = 0;
	while (from != until) {
		ret++;
		from++;
	}
	return ret;
}

/*
                        _ 
                       | |
  ___  __ _ _   _  __ _| |
 / _ \/ _` | | | |/ _` | |
|  __/ (_| | |_| | (_| | |
 \___|\__, |\__,_|\__,_|_|
         | |              
         |_|              
*/

// Compares the elements in the range (first1, last1) with those in the range beginning at first2, and returns true if all
// of the elements in both ranges match
// The elements are comparing using operator== or pred in version 2
template < class InputIterator1, class InputIterator2 >
bool	equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) { // equality
	while (first1 != last1) {
		if (!(*first1 == *first2))
			return false;
		first1++;
		first2++;
	}
	return true;
}
template < class InputIterator1, class InputIterator2, class BinaryPredicate >
bool	equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) { // predicate
	while (first1 != last1) {
		if (!pred(*first1, *first2))
			return false;
		first1++;
		first2++;
	}
	return true;
}

/*
 _           _                                 _     _           _ 
| |         (_)                               | |   (_)         | |
| | _____  ___  ___ ___   __ _ _ __ __ _ _ __ | |__  _  ___ __ _| |
| |/ _ \ \/ / |/ __/ _ \ / _` | '__/ _` | '_ \| '_ \| |/ __/ _` | |
| |  __/>  <| | (_| (_) | (_| | | | (_| | |_) | | | | | (_| (_| | |
|_|\___/_/\_\_|\___\___/ \__, |_|  \__,_| .__/|_| |_|_|\___\__,_|_|
                          __/ |         | |                        
                         |___/          |_|                        
*/

// Returns true if the range (first1, last1) compares lexicographically less than the range (first2, last2)
// A lexicographical comparison is the kind of comparison generally used to sort words alhabetically in
// dictionaries ; it involves comparing sequentially the elements that have the same position in both ranges
// against each other until one element is not equivalent ro the other
// The result of comparing these first non-matching elements is the result of lexicographical comparison
// If both sequences compare equal until one of them ends, the shorter sequence is lexicographically less than the longer one
// The elements are compared using operator< for the first version, and comp for the second
template < class InputIterator1, class InputIterator2 >
bool	lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) { // default
	while (first1 != last1) {
		if (first2 == last2 || *first2 < *first1)
			return false;
		else if (*first1 < *first2)
			return true;
		first1++;
		first2++;
	}
	return (first2 != last2);
}
template < class InputIterator1, class InputIterator2, class Compare >
bool	lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp) { // custom
	while (first1 != last1) {
		if (first2 == last2 || comp(*first2, *first1))
			return false;
		else if (comp(*first1, *first2))
			return true;
		first1++;
		first2++;
	}
	return (first2 != last2);
}

template < class T1, class T2 >
struct pair {

public:
	
	typedef T1	first_type;
	typedef T2	second_type;

	first_type	first;
	second_type	second;	

	pair () : first(first_type()), second(second_type()) {}
	template < class U, class V >
	pair (const pair<U,V> & pr) : first(pr.first), second(pr.second) {}
	pair (const first_type & a, const second_type & b) : first(a), second(b) {}

	pair &	operator= (const pair & pr) {
		new (this) pair(pr);
		return *this;
	}
};

template < class T1, class T2 >
pair<T1, T2> make_pair (T1 x, T2 y) {
	return (pair<T1, T2>(x, y));
}

template < class T >
class		node {
public:
	T			data;
	node	*parent;
	node	*left;
	node	*right;

	node	*_end;
	node	*_rend;

	int				height;
	bool			node_read;
	
	node() : data(T()), parent(NULL), left(NULL), right(NULL), _end(NULL), _rend(NULL), height(0), node_read(false) {}
	node(T & new_data) : data(new_data), parent(NULL), left(NULL), right(NULL), _end(NULL), _rend(NULL), height(0), node_read(false) {}
	node(const node & src) : data(src.data), parent(src.parent), left(src.left), right(src.right), _end(src._end), _rend(src._rend), height(src.height), node_read(src.node_read) {}
	node & operator=(const node & src) {
		new (this) node(src);

		return *this;	
	}

	operator const node<const T>() {
		node<const T>	ret(data);

		ret.parent = reinterpret_cast<node<const T> *>(parent);
		ret.left = reinterpret_cast<node<const T> *>(left);
		ret.right = reinterpret_cast<node<const T> *>(right);
		ret._end = reinterpret_cast<node<const T> *>(_end);
		ret._rend = reinterpret_cast<node<const T> *>(_rend);
		ret.height = height;
		ret.node_read = node_read;
		return ret;
	}
};



}
