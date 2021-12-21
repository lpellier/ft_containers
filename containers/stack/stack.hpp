#pragma once


namespace ft {

template < class T, class Container = ft::vector<T> >
class stack {
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
	typedef Container			container_type;
	typedef std::size_t			size_type;

	/*
	___  ___               _                  __                  _   _                 
	|  \/  |              | |                / _|                | | (_)                
	| .  . | ___ _ __ ___ | |__   ___ _ __  | |_ _   _ _ __   ___| |_ _  ___  _ __  ___ 
	| |\/| |/ _ \ '_ ` _ \| '_ \ / _ \ '__| |  _| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
	| |  | |  __/ | | | | | |_) |  __/ |    | | | |_| | | | | (__| |_| | (_) | | | \__ \
	\_|  |_/\___|_| |_| |_|_.__/ \___|_|    |_|  \__,_|_| |_|\___|\__|_|\___/|_| |_|___/
	*/

	// Constructs a stack with a copy of the underlying container
	explicit	stack (const container_type & ctnr = container_type()) {
		this->_container = ctnr;
	}

	// Returns whether the stack is empty: i.e. whether its size is zero
	bool		empty () const {
		return this->_container.empty();
	}

	// Returns the number of elements in the stack
	size_type	size () const {
		return this->_container.size();
	}

	// Returns a reference to the top element in the stack
	value_type &		top () {
		return this->_container.back();
	}
	const value_type &	top () const {
		return this->_container.back();
	}

	// Inserts a new element at the top of the stack, above its current top element
	// The content of this new element is initialized to a copy of val
	void	push (const value_type & val) {
		this->_container.push_back(val);
	}

	// Removes the element on top of the stack, effectively reducing its size by one
	void	pop () {
		this->_container.pop_back();
	}

protected:
	container_type	_container;

friend bool	operator== (const stack<T, Container>& lhs, const stack<T, Container>& rhs);
friend bool	operator!= (const stack<T, Container>& lhs, const stack<T, Container>& rhs);
friend bool	operator< (const stack<T, Container>& lhs, const stack<T, Container>& rhs);
friend bool	operator<= (const stack<T, Container>& lhs, const stack<T, Container>& rhs);
friend bool	operator> (const stack<T, Container>& lhs, const stack<T, Container>& rhs);
friend bool	operator>= (const stack<T, Container>& lhs, const stack<T, Container>& rhs);

};

/*
 _   _                                            _                 
| \ | |                                          | |                
|  \| | ___  _ __ ______ _ __ ___   ___ _ __ ___ | |__   ___ _ __  
| . ` |/ _ \| '_ \______| '_ ` _ \ / _ \ '_ ` _ \| '_ \ / _ \ '__| 
| |\  | (_) | | | |     | | | | | |  __/ | | | | | |_) |  __/ |    
\_| \_/\___/|_| |_|     |_| |_| |_|\___|_| |_| |_|_.__/ \___|_|    
  __                  _   _                                   _                 _     
/ _|                | | (_)                                 | |               | |    
| |_ _   _ _ __   ___| |_ _  ___  _ __     _____   _____ _ __| | ___   __ _  __| |___ 
|  _| | | | '_ \ / __| __| |/ _ \| '_ \   / _ \ \ / / _ \ '__| |/ _ \ / _` |/ _` / __|
| | | |_| | | | | (__| |_| | (_) | | | | | (_) \ V /  __/ |  | | (_) | (_| | (_| \__ \ 	
|_|  \__,_|_| |_|\___|\__|_|\___/|_| |_|  \___/ \_/ \___|_|  |_|\___/ \__,_|\__,_|___/                                                                                                                                 
*/

template < class T, class Container >
bool	operator== (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
	return (lhs._container == rhs._container);
}
template < class T, class Container >
bool	operator!= (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
	return (lhs._container != rhs._container);
}
template < class T, class Container >
bool	operator<  (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
	return (lhs._container < rhs._container);
}
template < class T, class Container >
bool	operator<= (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
	return (lhs._container <= rhs._container);
}
template < class T, class Container >
bool	operator>  (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
	return (lhs._container > rhs._container);
}
template < class T, class Container >
bool	operator>= (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
	return (lhs._container >= rhs._container);
}

}
