#pragma once

namespace ft {

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

	operator pair<const T1, const T2>() const {
		return pair<const T1, const T2>(const_cast<const T1>(first), const_cast<const T2>(second));
	}

	// TODO Comparison operators
};

template < class T1, class T2 >
pair<T1, T2> make_pair (T1 x, T2 y) {
	return (pair<T1, T2>(x, y));
}

};
	