#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <iterator>

namespace ft {

template < typename T >
class vector {
public:
	
	/*
	___  ___               _                 _____                     
	|  \/  |              | |               |_   _|                    
	| .  . | ___ _ __ ___ | |__   ___ _ __    | |_   _ _ __   ___  ___ 
	| |\/| |/ _ \ '_ ` _ \| '_ \ / _ \ '__|   | | | | | '_ \ / _ \/ __|
	| |  | |  __/ | | | | | |_) |  __/ |      | | |_| | |_) |  __/\__ \ 
	\_|  |_/\___|_| |_| |_|_.__/ \___|_|      \_/\__, | .__/ \___||___/
	                                              __/ | |              
	                                             |___/|_|         
	*/

	typedef T					value_type;
	typedef std::allocator<T>	allocator_type;

	// for default allocator : value_type &
	typedef typename allocator_type::reference			reference;
	// for default allocator : const value_type &
	typedef typename allocator_type::const_reference		const_reference;
	// for default allocator : value_type *
	typedef typename allocator_type::pointer				pointer;
	// for default allocator : const value_type *
	typedef typename allocator_type::const_pointer		const_pointer;

	// Iterators point to an element in a vector and point to the next one when incremented
	typedef std::iterator<std::random_access_iterator_tag, value_type>	iterator;
	// Reverse iterators point to an element in a vector and point to the previous one when incremented
	typedef std::reverse_iterator<iterator>								reverse_iterator;
	// A const iterator is an iteraror that points to const content
	typedef const iterator												const_iterator;
	// A const reverse iterator is a reverse iterator that points to const content
	typedef const reverse_iterator										const_reverse_iterator;

	typedef std::size_t			size_type;
	typedef std::ptrdiff_t		difference_type;

	/*
	 _____                         _           _ 
	/  __ \                       (_)         | |
	| /  \/ __ _ _ __   ___  _ __  _  ___ __ _| |
	| |    / _` | '_ \ / _ \| '_ \| |/ __/ _` | |
	| \__/\ (_| | | | | (_) | | | | | (_| (_| | |
	 \____/\__,_|_| |_|\___/|_| |_|_|\___\__,_|_| 
	*/

	// Default constructor
	vector<T> (void) {}

	// Parameter constructor that takes n values with val content
	vector<T> (size_type n, const value_type & val) {}

	// Parameter constructor that takes a range of iterators
	template < typename InputIterator >
	vector<T> (InputIterator first, InputIterator last) {}
	
	// Copy constructor
	vector<T> (const vector & src) {}

	// Destructor
	~vector<T> (void) {}
	
	// Assignment operator
	vector & operator= (vector<T> const & src) {}
	
	/*
	 _____ _                 _                 
	|_   _| |               | |                
	  | | | |_ ___ _ __ __ _| |_ ___  _ __ ___ 
	  | | | __/ _ \ '__/ _` | __/ _ \| '__/ __|
	 _| |_| ||  __/ | | (_| | || (_) | |  \__ \ 
	 \___/ \__\___|_|  \__,_|\__\___/|_|  |___/
	*/

	// Out of bounds iterators shall not be dereferenced
	// iterator, reverse_iterator, const_iterator and const_reverse_iterator are random access iterators (RAI)

	// Returns an iterator pointing to the first element in the vector
	iterator				begin () {}
	// If the vector is const-qualified
	const_iterator			begin () const {}

	// Returns an iterator pointing to the past-the-end element in the vector
	iterator				end () {}
	// If the vector is const-qualified
	const_iterator			end () const {}

	// Returns a reverse iterator pointing to the last element in the vector
	reverse_iterator		rbegin () {}
	// If the vector is const qualifed
	const_reverse_iterator	rbegin () const {}

	// Returns a reverse iterator pointing to the theroritocal element preceding the first element in the vector (which is considered its reverse end)
	reverse_iterator		rend () {}
	// If the vector is const qualifed
	const_reverse_iterator	rend () const {}

	/*
	 _____                        _ _         
	/  __ \                      (_) |        
	| /  \/ __ _ _ __   __ _  ___ _| |_ _   _ 
	| |    / _` | '_ \ / _` |/ __| | __| | | |
	| \__/\ (_| | |_) | (_| | (__| | |_| |_| |
	 \____/\__,_| .__/ \__,_|\___|_|\__|\__, |
	            | |                      __/ |
	            |_|                     |___/   
	*/

	// Capacity and size won't always be the same
	// Capacity may be equal or greater than size to acommodate for future growth of the vector 
	// without having to reallocate the whole array

	// Returns the number of elements in the vector
	size_type	size () const {}

	// Returns the maximum number of elements that the vector can hold
	size_type	max_size () const {}

	// Resizes the container so that it contains n elements
	void		resize (size_type n, value_type val = value_type()) {}

	// Returns the size of the storage space currently allocated for the vector, expressed in terms of elements
	size_type	capacity () const {}

	// Returns whether the vector is empty (i.e. whether its size is 0)
	bool		empty () const {}

	// Requests that the vector capacity be at least enough to contain n elements
	void		reserve (size_type n) {}

	/*
	 _____ _                           _      ___                        
	|  ___| |                         | |    / _ \                       
	| |__ | | ___ _ __ ___   ___ _ __ | |_  / /_\ \ ___ ___ ___  ___ ___ 
	|  __|| |/ _ \ '_ ` _ \ / _ \ '_ \| __| |  _  |/ __/ __/ _ \/ __/ __|
	| |___| |  __/ | | | | |  __/ | | | |_  | | | | (_| (_|  __/\__ \__ \ 
	\____/|_|\___|_| |_| |_|\___|_| |_|\__| \_| |_/\___\___\___||___/___/ 
	*/

	// Difference between at() and operator[] is that at() is safer and can throw an exception
	// Difference between front() and begin() is that begin() returns a reference instead of an iterator

	// Returns a reference to the element at position n in the vector container
	reference			operator[] (size_type n) {}
	// If the vector is const-qualifed
	const_reference		operator[] (size_type n) const {}

	// Returns a reference to the element at position n in the vector
	reference			at (size_type n) {}
	// If the vector is const-qualifed
	const_reference		at (size_type n) const {}

	// Returns a reference to the first element in the vector
	reference			front () {}
	// If the vector is const-qualified
	const_reference		front () const {}

	// Returns a reference to the last element in the vector
	reference			back () {}
	// If the vector is const-qualified
	const_reference		back () const {}

	/*
	___  ___          _ _  __ _               
	|  \/  |         | (_)/ _(_)              
	| .  . | ___   __| |_| |_ _  ___ _ __ ___ 
	| |\/| |/ _ \ / _` | |  _| |/ _ \ '__/ __|
	| |  | | (_) | (_| | | | | |  __/ |  \__ \ 
	\_|  |_/\___/ \__,_|_|_| |_|\___|_|  |___/ 
	*/

	// Asign new contents to the vector, replacing its current contents, and modifying its size accordingly
	template	< typename InputIterator >
	void		assign (InputIterator first, InputIterator last) {} // range
	void		assign (size_type n, const value_type & val) {} // fill
	
	// Adds a new element at the end of the vector, after its current last element
	// The content of val is copied (or moved) to the new element
	void		push_back (const value_type & val) {}

	// Removes the last element in the vector, effectively reducing the container size by one
	// This destroys the removed element
	void		pop_back () {}

	// The vector is extended by inserting new elements before the element at the specified position,
	// effectively increasing the container size by the number of elements inserted
	iterator	insert (iterator position, const value_type & val) {} // single element
	void		insert (iterator position, size_type n, const value_type & val) {} // fill
	template	< typename InputIterator >
	void		insert (iterator position, InputIterator first, InputIterator last) {} // range

	// Removes from the vector either a single elemnt (position) or a range of elements [first, last)
	// This effectively reduces the container size by the number of elements removed, which are destroyed
	iterator	erase (iterator position) {} // single element
	iterator	erase (iterator first, iterator last) {} // range

	// Exchanges the content of the vector by the content of x, which is another vector object of the same type
	// Sizes may differ
	void		swap (vector<T> & x) {}

	// Removes all elements from the vector (which are destroyed), leaving the container with a size of 0
	void		clear () {}

	/*
	  ___  _ _                 _             
	 / _ \| | |               | |            
	/ /_\ \ | | ___   ___ __ _| |_ ___  _ __ 
	|  _  | | |/ _ \ / __/ _` | __/ _ \| '__|
	| | | | | | (_) | (_| (_| | || (_) | |   
	\_| |_/_|_|\___/ \___\__,_|\__\___/|_|         
	*/

	// Returns a copy of the allocator object associated with the vector
	allocator_type	get_allocator () const {}                     

protected:
	/*
	 _   _           _             _   _            _                     _ 
	| | | |         | |           | | | |          | |                   | |
	| | | |_ __   __| | ___ _ __  | |_| |__   ___  | |__   ___   ___   __| |
	| | | | '_ \ / _` |/ _ \ '__| | __| '_ \ / _ \ | '_ \ / _ \ / _ \ / _` |
	| |_| | | | | (_| |  __/ |    | |_| | | |  __/ | | | | (_) | (_) | (_| |
	\___/|_| |_|\__,_|\___|_|     \__|_| |_|\___| |_| |_|\___/ \___/ \__,_|                            
	*/

	// Increases the size of the vector while reallocating if new size is over capacity
	void	increase_size (size_type n) {}

	// Reallocates enough memory for new capacity of old_capacity + n
	void	increase_capacity (size_type n) {}
};

/*
 _   _                                            _                  __                  _   _                                   _                 _     
| \ | |                                          | |                / _|                | | (_)                                 | |               | |    
|  \| | ___  _ __ ______ _ __ ___   ___ _ __ ___ | |__   ___ _ __  | |_ _   _ _ __   ___| |_ _  ___  _ __     _____   _____ _ __| | ___   __ _  __| |___ 
| . ` |/ _ \| '_ \______| '_ ` _ \ / _ \ '_ ` _ \| '_ \ / _ \ '__| |  _| | | | '_ \ / __| __| |/ _ \| '_ \   / _ \ \ / / _ \ '__| |/ _ \ / _` |/ _` / __|
| |\  | (_) | | | |     | | | | | |  __/ | | | | | |_) |  __/ |    | | | |_| | | | | (__| |_| | (_) | | | | | (_) \ V /  __/ |  | | (_) | (_| | (_| \__ \ 	
\_| \_/\___/|_| |_|     |_| |_| |_|\___|_| |_| |_|_.__/ \___|_|    |_|  \__,_|_| |_|\___|\__|_|\___/|_| |_|  \___/ \_/ \___|_|  |_|\___/ \__,_|\__,_|___/                                                                                                                                 
*/

template	< typename T >
void		swap (vector<T> & x, vector<T> & y) {}
template	< typename T >
bool		operator== (const vector<T> & lhs, const vector<T> & rhs) {}
template	< typename T >
bool		operator!= (const vector<T> & lhs, const vector<T> & rhs) {}
template	< typename T >
bool		operator>= (const vector<T> & lhs, const vector<T> & rhs) {}
template	< typename T >
bool		operator<= (const vector<T> & lhs, const vector<T> & rhs) {}
template	< typename T >
bool		operator>  (const vector<T> & lhs, const vector<T> & rhs) {}
template	< typename T >
bool		operator<  (const vector<T> & lhs, const vector<T> & rhs) {}

}

#endif
