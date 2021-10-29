#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <vector>
#include <iterator>

template <
	typename T,
	typename Allocator = std::allocator<T>
>
class Vector {
public:
	
	//  ___  ___               _                 _____                     
	//  |  \/  |              | |               |_   _|                    
	//  | .  . | ___ _ __ ___ | |__   ___ _ __    | |_   _ _ __   ___  ___ 
	//  | |\/| |/ _ \ '_ ` _ \| '_ \ / _ \ '__|   | | | | | '_ \ / _ \/ __|
	//  | |  | |  __/ | | | | | |_) |  __/ |      | | |_| | |_) |  __/\__ \ 
	//  \_|  |_/\___|_| |_| |_|_.__/ \___|_|      \_/\__, | .__/ \___||___/
	//                                                __/ | |              
	//                                               |___/|_|         

	typedef T			value_type;
	typedef Allocator	allocator_type;

	// for default allocator : value_type &
	typedef allocator_type::reference			reference;
	// for default allocator : const value_type &
	typedef allocator_type::const_reference		const_reference;
	// for default allocator : value_type *
	typedef allocator_type::pointer				pointer;
	// for default allocator : const value_type *
	typedef allocator_type::const_pointer		const_pointer;

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

	//   _____                         _           _ 
	//  /  __ \                       (_)         | |
	//  | /  \/ __ _ _ __   ___  _ __  _  ___ __ _| |
	//  | |    / _` | '_ \ / _ \| '_ \| |/ __/ _` | |
	//  | \__/\ (_| | | | | (_) | | | | | (_| (_| | |
	//   \____/\__,_|_| |_|\___/|_| |_|_|\___\__,_|_| 

	// Default constructor
	Vector<T, Allocator> (void) {}

	// Parameter constructors
	Vector<T, Allocator> (size_type n, const value_type & val) {}

	template < typename InputIterator >
	Vector<T, Allocator> (InputIterator first, InputIterator last) {}
	
	// Copy constructor
	Vector<T, Allocator> (const Vector & src);

	// Destructor
	~Vector<T, Allocator> (void) {}
	
	// Assignment operator
	Vector & operator= (Vector<T, Allocator> const & src);
	
	//   _____ _                 _                 
	//  |_   _| |               | |                
	//    | | | |_ ___ _ __ __ _| |_ ___  _ __ ___ 
	//    | | | __/ _ \ '__/ _` | __/ _ \| '__/ __|
	//   _| |_| ||  __/ | | (_| | || (_) | |  \__ \ 
	//   \___/ \__\___|_|  \__,_|\__\___/|_|  |___/

	// Out of bounds iterators shall not be dereferenced
	// iterator, reverse_iterator, const_iterator and const_reverse_iterator are random access iterators (RAI)

	// Returns an iterator pointing to the first element in the vector
	iterator				begin ();
	// If the vector is const-qualified
	const_iterator			begin () const;

	// Returns an iterator pointing to the past-the-end element in the vector
	iterator				end ();
	// If the vector is const-qualified
	const_iterator			end () const;

	// Returns a reverse iterator pointing to the last element in the vector
	reverse_iterator		rbegin ();
	// If the vector is const qualifed
	const_reverse_iterator	rbegin () const;

	// Returns a reverse iterator pointing to the theroritocal element preceding the first element in the vector (which is considered its reverse end)
	reverse_iterator		rend ();
	// If the vector is const qualifed
	const_reverse_iterator	rend () const;

	// Returns a const iterator pointing to the first element in the vector
	const_iterator			cbegin () const noexcept;

	// Returns a const iterator pointing to the past-the-end element in the vector
	const_iterator			cend () const noexcept;

	// Returns a const reverse iterator pointing to the last element in the vector
	const_reverse_iterator	crbegin () const noexcept;

	// Returns a reverse iterator pointing to the theroritocal element preceding the first element in the vector (which is considered its reverse end)
	const_reverse_iterator	crend () const noexcept;

	//   _____                        _ _         
	//  /  __ \                      (_) |        
	//  | /  \/ __ _ _ __   __ _  ___ _| |_ _   _ 
	//  | |    / _` | '_ \ / _` |/ __| | __| | | |
	//  | \__/\ (_| | |_) | (_| | (__| | |_| |_| |
	//   \____/\__,_| .__/ \__,_|\___|_|\__|\__, |
	//              | |                      __/ |
	//              |_|                     |___/   

	// Capacity and size won't always be the same
	// Capacity may be equal or greater than size to acommodate for future growth of the vector 
	// without having to reallocate the whole array

	// Returns the number of elements in the vector
	size_type	size () const;

	// Returns the maximum number of elements that the vector can hold
	size_type	max_size () const;

	// Resizes the container so that it contains n elements
	void		resize (size_type n, value_type val = value_type());

	// Returns the size of the storage space currently allocated for the vector, expressed in terms of elements
	size_type	capacity () const;

	// Returns whether the vector is empty (i.e. whether its size is 0)
	bool		empty () const;

	// Requests that the vector capacity be at least enough to contain n elements
	void		reserve (size_type n);

	// Requests the container to reduce its capacity to fit its size
	void		shrink_to_fit ();

	//   _____ _                           _      ___                        
	//  |  ___| |                         | |    / _ \                       
	//  | |__ | | ___ _ __ ___   ___ _ __ | |_  / /_\ \ ___ ___ ___  ___ ___ 
	//  |  __|| |/ _ \ '_ ` _ \ / _ \ '_ \| __| |  _  |/ __/ __/ _ \/ __/ __|
	//  | |___| |  __/ | | | | |  __/ | | | |_  | | | | (_| (_|  __/\__ \__ \ 
	//  \____/|_|\___|_| |_| |_|\___|_| |_|\__| \_| |_/\___\___\___||___/___/ 

	// Difference between at() and operator[] is that at() is safer and can throw an exception
	// Difference between front() and begin() is that begin() returns a reference instead of an iterator

	// Returns a reference to the element at position n in the vector container
	reference			operator[] (size_type n);
	// If the vector is const-qualifed
	const_reference		operator[] (size_type n) const;

	// Returns a reference to the element at position n in the vector
	reference			at (size_type n);
	// If the vector is const-qualifed
	const_reference		at (size_type n) const;

	// Returns a reference to the first element in the vector
	reference			front ();
	// If the vector is const-qualified
	const_reference		front () const;

	// Returns a reference to the last element in the vector
	reference			back ();
	// If the vector is const-qualified
	const_reference		back ();

	// Returns a direct pointer to the memory array used internally by the vector to store its owned elements
	value_type *		data () noexcept;
	// If the vector is const-qualified
	const valut_type *	data () const noexcept;

	//  ___  ___          _ _  __ _               
	//  |  \/  |         | (_)/ _(_)              
	//  | .  . | ___   __| |_| |_ _  ___ _ __ ___ 
	//  | |\/| |/ _ \ / _` | |  _| |/ _ \ '__/ __|
	//  | |  | | (_) | (_| | | | | |  __/ |  \__ \ 
	//  \_|  |_/\___/ \__,_|_|_| |_|\___|_|  |___/ 


	//    ___  _ _                 _             
	//   / _ \| | |               | |            
	//  / /_\ \ | | ___   ___ __ _| |_ ___  _ __ 
	//  |  _  | | |/ _ \ / __/ _` | __/ _ \| '__|
	//  | | | | | | (_) | (_| (_| | || (_) | |   
	//  \_| |_/_|_|\___/ \___\__,_|\__\___/|_|         

	// Returns a copy of the allocator object associated with the vector
	allocator_type	get_allocator () const;                     

};

//   _   _                                            _                  __                  _   _                                   _                 _     
//  | \ | |                                          | |                / _|                | | (_)                                 | |               | |    
//  |  \| | ___  _ __ ______ _ __ ___   ___ _ __ ___ | |__   ___ _ __  | |_ _   _ _ __   ___| |_ _  ___  _ __     _____   _____ _ __| | ___   __ _  __| |___ 
//  | . ` |/ _ \| '_ \______| '_ ` _ \ / _ \ '_ ` _ \| '_ \ / _ \ '__| |  _| | | | '_ \ / __| __| |/ _ \| '_ \   / _ \ \ / / _ \ '__| |/ _ \ / _` |/ _` / __|
//  | |\  | (_) | | | |     | | | | | |  __/ | | | | | |_) |  __/ |    | | | |_| | | | | (__| |_| | (_) | | | | | (_) \ V /  __/ |  | | (_) | (_| | (_| \__ \ 
//  \_| \_/\___/|_| |_|     |_| |_| |_|\___|_| |_| |_|_.__/ \___|_|    |_|  \__,_|_| |_|\___|\__|_|\___/|_| |_|  \___/ \_/ \___|_|  |_|\___/ \__,_|\__,_|___/                                                                                                                                 

template	<nametype T, nametype Allocator>
void		swap (Vector<T, Allocator> & x, Vector<T, Allocator> & y);
template	<nametype T, nametype Allocator>
bool		operator== (const vector<T, Allocator> & lhs, const vector<T, Allocator> & rhs);
template	<nametype T, nametype Allocator>
bool		operator!= (const vector<T, Allocator> & lhs, const vector<T, Allocator> & rhs);
template	<nametype T, nametype Allocator>
bool		operator>= (const vector<T, Allocator> & lhs, const vector<T, Allocator> & rhs);
template	<nametype T, nametype Allocator>
bool		operator<= (const vector<T, Allocator> & lhs, const vector<T, Allocator> & rhs);
template	<nametype T, nametype Allocator>
bool		operator>  (const vector<T, Allocator> & lhs, const vector<T, Allocator> & rhs);
template	<nametype T, nametype Allocator>
bool		operator<  (const vector<T, Allocator> & lhs, const vector<T, Allocator> & rhs);


#endif
