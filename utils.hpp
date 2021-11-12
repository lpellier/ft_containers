#ifndef UTILS_HPP
# define UTILS_HPP

#include <cstddef>
#include <iostream>
#include "type_traits.hpp"

const // It is a const object...
class nullptr_t
{
  public:
    template<class T>
    inline operator T*() const // convertible to any type of null non-member pointer...
    { return 0; }

    template<class C, class T>
    inline operator T C::*() const   // or any type of null member pointer...
    { return 0; }

  private:
    void operator&() const;  // Can't take address of nullptr

} nullptr = {};

namespace ft {
/*
                  _     _         _  __ 
                 | |   | |       (_)/ _|
  ___ _ __   __ _| |__ | | ___    _| |_ 
 / _ \ '_ \ / _` | '_ \| |/ _ \  | |  _|
|  __/ | | | (_| | |_) | |  __/  | | |  
 \___|_| |_|\__,_|_.__/|_|\___|  |_|_|  
*/

template < bool B, typename T = void >
struct enable_if {};

template < typename T >
struct enable_if<true, T> { typedef T type; };

/*
     _ _     _                       
    | (_)   | |                      
  __| |_ ___| |_ __ _ _ __   ___ ___ 
 / _` | / __| __/ _` | '_ \ / __/ _ \
| (_| | \__ \ || (_| | | | | (_|  __/
 \__,_|_|___/\__\__,_|_| |_|\___\___|
*/

template < typename Iter >
typename ft::iterator_traits<Iter>::difference_type	distance(Iter from, Iter until) {
	typename ft::iterator_traits<Iter>::difference_type ret = 0;
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

}

#endif
