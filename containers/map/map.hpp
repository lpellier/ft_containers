
#pragma once

namespace ft {

template <	class Key,												// map::key_type
			class T,												// map::mapped_type
			class Compare = std::less<Key>,							// map::key_compare
			class Alloc = std::allocator<std::pair<const Key,T> >	// map::allocator_type
			> 
class map {
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

	// Type of the keys
	// Each element in a map is uniquely identified by its key value
	typedef Key		key_type;
	// Type of the mapped value
	// Each element in a map stores some data as its mapped value
	typedef T		mapped_type;
	// A binary predicate that takes two elements keys as arguments and returns a bool
	// The expression comp(a, b), where comp is an object of this type and a and b
	// are key values, shall return true if a is considered to go before b in the
	// strict weak ordering the function defines
	typedef Compare	key_compare;
	// Type of the allocator (by default : std::allocator)
	typedef Alloc	allocator_type;
	
	typedef typename ft::pair<key_type, mapped_type>	value_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
	
	// typedef ft::bidirectional_iterator<value_type>			iterator;
	// typedef ft::bidirectional_iterator<const value_type>	const_iterator;
	// typedef ft::reverse_iterator<iterator>					reverse_iterator;
	// typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
	
	typedef std::ptrdiff_t	difference_type;
	typedef std::size_t		size_type;

	/*
	 _____                         _           _ 
	/  __ \                       (_)         | |
	| /  \/ __ _ _ __   ___  _ __  _  ___ __ _| |
	| |    / _` | '_ \ / _ \| '_ \| |/ __/ _` | |
	| \__/\ (_| | | | | (_) | | | | | (_| (_| | |
	 \____/\__,_|_| |_|\___/|_| |_|_|\___\__,_|_| 
	*/

	// Constructs an empty map, with no elements
	// explicit	map (const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type()) { // empty
	// }

	// Constructs a map with as many elements as the range [first, last],
	// with each element constructed from its corresponding element
	// in that range, in the same order
	template < class InputIterator >
	// using enable_if here forbids any integral type to get into this function
	// so that only iterators may use this function
	map (InputIterator first, InputIterator last, const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type()) { // range
		_root = NULL;
		_size = 0;
		_comp = comp;
		_alloc = alloc;
		while (first != last) {
			int val = rand() % 100 + 1;
			_add_node(&_root, make_pair(val, val));
			first++;
			_size++;
		}
		_display_tree("", _root, false, (_root->right ? true : false));
		int balanced = is_balanced(_root);
		std::cout << "Is tree balanced ? " << (balanced > 0 ? "No" : "Yes")  << std::endl;
	}

	// Constructs a map with a copy of each of the elements in x
	// map (const map & x) { // copy

	// }

	// This destroys all map elements, and deallocates all the storage capacity allocated by the map container
	// using its allocator
	~map () {

	}

	// Assigns new contents to the container, replacing its current content and changing its size accordingly
	// The map preserves its current allocator, which is used to allocate additional storage if needed
	// map &	operator= (const map & x) {

	// }

	/*
	_____ _                 _                 
	|_   _| |               | |                
	| | | |_ ___ _ __ __ _| |_ ___  _ __ ___ 
	| | | __/ _ \ '__/ _` | __/ _ \| '__/ __|
	_| |_| ||  __/ | | (_| | || (_) | |  \__ \
	\___/ \__\___|_|  \__,_|\__\___/|_|  |___/
	*/

	// // Returns an iterator reffering to the first element in the map container
	// iterator		begin() {

	// }
	// // If the map is const_qualified
	// const_iterator	begin() const {
		
	// }

	// // Returns an iterator reffering to the past-the-end element in the map container
	// iterator		end() {

	// }
	// // If the map is const_qualified
	// const_iterator	end() const {
		
	// }

	// // Returns a reverse_iterator reffering to the last element in the map container
	// reverse_iterator		begin() {

	// }
	// // If the map is const_qualified
	// const_reverse_iterator	begin() const {
		
	// }

	// // Returns a reverse iterator pointing to the theroritocal element preceding the 
	// // first element in the map (which is considered its reverse end)
	// reverse_iterator		end() {

	// }
	// // If the map is const_qualified
	// const_reverse_iterator	end() const {
		
	// }

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

	// Returns whether the map container is empty
	bool	empty () const {

	}

	// Returns the number of elements in the map container
	size_type	size () const {

	}

	// Returns the maximum number of elements that the map container can hold
	size_type	max_size () const {

	}

	/*
	 _____ _                           _      ___                        
	|  ___| |                         | |    / _ \                       
	| |__ | | ___ _ __ ___   ___ _ __ | |_  / /_\ \ ___ ___ ___  ___ ___ 
	|  __|| |/ _ \ '_ ` _ \ / _ \ '_ \| __| |  _  |/ __/ __/ _ \/ __/ __|
	| |___| |  __/ | | | | |  __/ | | | |_  | | | | (_| (_|  __/\__ \__ \ 
	\____/|_|\___|_| |_| |_|\___|_| |_|\__| \_| |_/\___\___\___||___/___/ 
	*/

	// If k matches the key of an element in the container, the functions returns
	// a reference to its mapped value
	// If not, the function inserts a new element with thay key and returns
	// a reference to it's mapped value.
	// The element is constructed using the default constructor
	// mapped_type &	operator[] (const key_type & k) {

	// }

	/*
	___  ___          _ _  __ _               
	|  \/  |         | (_)/ _(_)              
	| .  . | ___   __| |_| |_ _  ___ _ __ ___ 
	| |\/| |/ _ \ / _` | |  _| |/ _ \ '__/ __|
	| |  | | (_) | (_| | | | | |  __/ |  \__ \ 
	\_|  |_/\___/ \__,_|_|_| |_|\___|_|  |___/ 
	*/

	// Extends the container by inserting new elements, effectively increasing the
	// container size by the number of elements inserted
	// Because element keys in a map are unique, the insertion operation checks
	// whether each inserted element has a key equivalent to the one of an element
	// already in the container, and if so, the the element is not inserted,
	// returning an iterator to this existing element
	// pair<iterator, bool>	insert (const value_type & val) { // single element

	// }
	// iterator				insert (iterator position, const value_type & val) { // fill

	// }
	// template < class InputIterator >
	// void					insert (InputIterator first, InputIterator, last) { // range

	// }

	// Removes from the map container either a single element of a range of elements
	// This effectively reduces the container size by the number of elements removed,
	// which are destroyed
	// void		erase (iterator position) {

	// }
	// size_type	erase (const key_type & k) {

	// }
	// void		erase (iterator first, iterator last) {

	// }

	// Exchanges the content of the container by the content of x, which is another map
	// of the same type; sizes may differ
	// void	swap (map & x) {

	// }

	// Removes all elements from the map container (which are destroyed),
	// leaving the container with a size of 0
	// void	clear () {

	// }

	/*
	 _____ _                                      
	|  _  | |                                     
	| | | | |__  ___  ___ _ ____   _____ _ __ ___ 
	| | | | '_ \/ __|/ _ \ '__\ \ / / _ \ '__/ __|
	\ \_/ / |_) \__ \  __/ |   \ V /  __/ |  \__ \
	\___/|_.__/|___/\___|_|    \_/ \___|_|  |___/
	*/

	// Returns a copy of the comparison object used by the
	// map container to compare keys
	// key_compare	key_comp () const {

	// }

	// Returns a comparison object that can be used to compare two
	// elements to get whether the key of the first one goes before the second
	// value_compare value_comp() const {

	// }

	/*
	_____                      _   _                 
	|  _  |                    | | (_)                
	| | | |_ __   ___ _ __ __ _| |_ _  ___  _ __  ___ 
	| | | | '_ \ / _ \ '__/ _` | __| |/ _ \| '_ \/ __|
	\ \_/ / |_) |  __/ | | (_| | |_| | (_) | | | \__ \
	\___/| .__/ \___|_|  \__,_|\__|_|\___/|_| |_|___/
		| |                                         
		|_|                                         
	*/

	// Seaches the container for an element with a key equivalent to k
	// and returns an iterator to it if found, otherwise returns map::end
	// Two keys are considered equivalent if the container's comparison
	// object returns false reflexively (i.e., no matter the order in which
	// the elements are passed as arguments)
	// iterator		find (const key_type & k) {

	// }
	// const_iterator	find (const key_type & k) const {

	// }

	// Search the container for elements with a key equivalent to k and
	// returns the number of matches
	// Because all elements in a map container are unique, the function can
	// only return 1 or 0
	// size_type		count (const key_type & k) const {

	// }

	// Returns an iterator pointing to the first element in the container
	// whose key is not considered to go before k (i.e., either it is equivalent
	// or goes after)
	// iterator		lower_bound (const key_type & k) {

	// }
	// // If the map is const-qualified
	// const_iterator	lower_bound (const key_type & k) const {
		
	// }

	// Returns an iterator pointing to the first element in the container
	// whose ket is considered to go after k
	// iterator		upper_bound (const key_type & k) {

	// }
	// const_iterator	upper_bound (const key_type & k) const {
		
	// }

	// Returns the bounds of a range that includes all the elements in the
	// container which have a key equivalent to k
	// Because the elements in a map container have unique keys, the range returned
	// will contain a single element at most
	// pair<iterator, iterator>				equal_range (const key_type & k) {

	// }
	// pair<const_iterator, const_iterator>	equal_range (const key_type & k) const {

	// }

	/*
	  ___  _ _                 _             
	 / _ \| | |               | |            
	/ /_\ \ | | ___   ___ __ _| |_ ___  _ __ 
	|  _  | | |/ _ \ / __/ _` | __/ _ \| '__|
	| | | | | | (_) | (_| (_| | || (_) | |   
	\_| |_/_|_|\___/ \___\__,_|\__\___/|_|         
	*/

	// Returns a copy of the allocator object associated with the map
	// allocator_type	get_allocator () const {

	// }

protected:

	/*
	 _   _           _             _   _            _                     _ 
	| | | |         | |           | | | |          | |                   | |
	| | | |_ __   __| | ___ _ __  | |_| |__   ___  | |__   ___   ___   __| |
	| | | | '_ \ / _` |/ _ \ '__| | __| '_ \ / _ \ | '_ \ / _ \ / _ \ / _` |
	| |_| | | | | (_| |  __/ |    | |_| | | |  __/ | | | | (_) | (_) | (_| |
	\___/|_| |_|\__,_|\___|_|     \__|_| |_|\___| |_| |_|\___/ \___/ \__,_|                            
	*/

	typedef struct		s_node {
		value_type		data;
		int				height;
		struct s_node	*left;
		struct s_node	*right;
	}					t_node;

	// to allocate storage
	allocator_type	_alloc;
	// to sort the elements
	key_compare		_comp;
	// size of map
	size_type		_size;
	// root of binary tree
	t_node *			_root;

	int		maxChildHeight(t_node * node) {
		if (!node || (!node->left && !node->right))
			return (0);
		if (!node->left)
			return node->right->height;
		if (!node->right)
			return node->left->height;
		return (node->left->height > node->right->height ? node->left->height : node->right->height);
	}

	bool		is_balanced(t_node * node) {
		if (!node)
			return true;
		if (abs(getBalance(node)) <= 1 && is_balanced(node->left) && is_balanced(node->right))
			return true;
		return false;
	}

	int		getBalance(t_node * node) {
		if (!node || (!node->left && !node->right))
			return (0);
		if (!node->left)
			return -node->right->height;
		if (!node->right)
			return node->left->height;
		return node->left->height - node->right->height;
	}

	// A utility function to right
	// rotate subtree rooted with y
	// See the diagram given above.
	void	rightRotate(t_node **tree)
	{
		t_node *y = *tree;
		t_node *x = y->left;
		if (!x)
			return;
		t_node *T2 = x->right;
			
		// Perform rotation
		x->right = y;
		y->left = T2;
	
		// Update heights
		y->height = 1 + maxChildHeight(y);
		x->height = 1 + maxChildHeight(x);
		
		// Return new root
		*tree = x;
	}
	
	// A utility function to left
	// rotate subtree rooted with x
	// See the diagram given above.
void	leftRotate(t_node **tree)
	{
		t_node *x = *tree;
		t_node *y = x->right;
		if (!y)
			return;
		t_node *T2 = y->left;
	
		// Perform rotation
		x->right = T2;
		y->left = x;
	
		// Update heights
		x->height = 1 + maxChildHeight(x);
		y->height = 1 + maxChildHeight(y);
		
		// Return new root
		*tree = y;
	}

	void	_add_node(t_node ** node, const value_type & val) {
		t_node *	tmp = NULL;
		// inefficient
		if (_search_node(node, val))
			return ;
		if (!(*node)) {
			tmp = (t_node *)malloc(sizeof(t_node));
			if (!tmp)
				throw std::bad_alloc();
			tmp->left = tmp->right = NULL;
			tmp->data = val;
			tmp->height = 1;
			*node = tmp;
		}
		else {
			if (_comp(val.second, (*node)->data.second))
				_add_node(&(*node)->left, val);
			else if (!_comp(val.second, (*node)->data.second))
				_add_node(&(*node)->right, val);
			else
				return ;
			
			(*node)->height = 1 + maxChildHeight(*node);
			int balance = getBalance(*node);
			std::cout << "node " << (*node)->data.second << " balance : " << balance << std::endl;

			// Left left case
			if (balance < -1 || balance > 1) {
				_display_tree("", _root, false, (_root->right ? true : false));
				std::cout << std::endl;
			}
			if ((*node)->left && balance > 1 && _comp(val.second, (*node)->left->data.second))
				rightRotate(node);
			
			// Right Right Case
			if ((*node)->right && balance < -1 && !_comp(val.second, (*node)->right->data.second))
				leftRotate(node);
		
			// Left Right Case
			if ((*node)->left && balance > 1 && !_comp(val.second, (*node)->left->data.second))
			{
				leftRotate(&((*node)->left));
				rightRotate(node);
			}
		
			// Right Left Case
			if ((*node)->right && balance < -1 && _comp(val.second, (*node)->right->data.second))
			{
				rightRotate(&((*node)->right));
				leftRotate(node);
			}
			if (balance < -1 || balance > 1) {
				_display_tree("", _root, false, (_root->right ? true : false));
				std::cout << std::endl << std::endl;
			}
		}
	}

	t_node *	_search_node(t_node ** node, const value_type & val) {
		if (!(*node))
			return (NULL);
		if (val.first == (*node)->data.first)
			return *node;
		else if (_comp(val.first, (*node)->data.first))
			return _search_node(&(*node)->left, val);
		else if (!_comp(val.first, (*node)->data.first))
			return _search_node(&(*node)->right, val);
		return (NULL);
	}

	void	_delete_tree(t_node * node) {
		if (node) {
			_delete_tree(node->left);
			_delete_tree(node->right);
			free(node);
		}
	}

	void	_display_tree(const std::string & prefix, t_node * node, bool isLeft, bool childInRight) {
		if (node) {
			std::cout << prefix;
			std::cout << (isLeft && childInRight ? "├──" : "└──");
			std::cout << (isLeft ? "\e[34m" : "\e[31m");
			std::cout << node->data.second << std::endl;
			std::cout << "\e[0m";
			_display_tree(prefix + (isLeft && childInRight ? "│   " : "    "), node->left, true, (node->right ? true : false));
			_display_tree(prefix + (isLeft && childInRight ? "│   " : "    "), node->right, false, (node->right ? true : false));
		}
	}

	class value_compare : std::binary_function<value_type, value_type, bool> {
	protected:
		key_compare	comp;
		value_compare (key_compare c) : comp(c) {}

	public:
		typedef bool		result_type;
		typedef value_type	first_argument_type;
		typedef value_type	second_argument_type;
		bool operator() (const value_type & x, const value_type & y) const {
			return comp(x.first, y.first);
		}
	};
};

}
