#pragma once

#ifdef __APPLE__
#include <stdint.h>
#else
#include <uchar.h>
#endif

namespace ft {

/*
 _ _                 _                         _                        _           
(_) |               | |                       | |                      (_)          
 _| |_ ___ _ __ __ _| |_ ___  _ __    ___ __ _| |_ ___  __ _  ___  _ __ _  ___  ___ 
| | __/ _ \ '__/ _` | __/ _ \| '__|  / __/ _` | __/ _ \/ _` |/ _ \| '__| |/ _ \/ __|
| | ||  __/ | | (_| | || (_) | |    | (_| (_| | ||  __/ (_| | (_) | |  | |  __/\__ \
|_|\__\___|_|  \__,_|\__\___/|_|     \___\__,_|\__\___|\__, |\___/|_|  |_|\___||___/
                                                        __/ |                       
                                                       |___/                        
*/

struct input_interator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag {};
struct bidirectional_iterator_tag {};
struct random_access_iterator_tag {};

/*
 _ _                 _               _             _ _       
(_) |               | |             | |           (_) |      
 _| |_ ___ _ __ __ _| |_ ___  _ __  | |_ _ __ __ _ _| |_ ___ 
| | __/ _ \ '__/ _` | __/ _ \| '__| | __| '__/ _` | | __/ __|
| | ||  __/ | | (_| | || (_) | |_   | |_| | | (_| | | |_\__ \
|_|\__\___|_|  \__,_|\__\___/|_(_)   \__|_|  \__,_|_|\__|___/
*/

template < typename Iter >
struct iterator_traits {
	typedef typename Iter::difference_type		difference_type;
	typedef typename Iter::value_type			value_type;
	typedef typename Iter::pointer				pointer;
	typedef typename Iter::reference			reference;
	typedef typename Iter::iterator_category	iterator_category;
};

template < typename T >
struct iterator_traits<T*> {
	typedef std::ptrdiff_t					difference_type;
	typedef T								value_type;
	typedef T *								pointer;
	typedef T &								reference;
	typedef random_access_iterator_tag	iterator_category;
};

template < typename T >
struct iterator_traits<const T*> {
	typedef std::ptrdiff_t					difference_type;
	typedef T								value_type;
	typedef const T *						pointer;
	typedef const T &						reference;
	typedef random_access_iterator_tag	iterator_category;
};

/*
 _        _       _                       _ 
(_)      (_)     | |                     | |
 _ ___    _ _ __ | |_ ___  __ _ _ __ __ _| |
| / __|  | | '_ \| __/ _ \/ _` | '__/ _` | |
| \__ \  | | | | | ||  __/ (_| | | | (_| | |
|_|___/  |_|_| |_|\__\___|\__, |_|  \__,_|_|
                           __/ |            
                          |___/             
*/

template <bool B>
struct bool_wrapper {
	static const bool value = B;
};

// check if type is const

template < typename T >
struct is_const : bool_wrapper<false> {};

template < typename T >
struct is_const<const T> : bool_wrapper<true> {};

// integral types : bool, char, char_16t, char32_t, wchar_t, short, int, long, long long

template < typename T >
struct is_integral : bool_wrapper<false> {};

template <>
struct is_integral<bool> : bool_wrapper<true> {};
template <>
struct is_integral<char> : bool_wrapper<true> {};
template <>
struct is_integral<char16_t> : bool_wrapper<true> {};
template <>
struct is_integral<char32_t> : bool_wrapper<true> {};
template <>
struct is_integral<wchar_t> : bool_wrapper<true> {};
template <>
struct is_integral<short> : bool_wrapper<true> {};
template <>
struct is_integral<int> : bool_wrapper<true> {};
template <>
struct is_integral<long> : bool_wrapper<true> {};
template <>
struct is_integral<long long> : bool_wrapper<true> {};
}
