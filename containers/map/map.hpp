#pragma once

#include "iterator/iterator.hpp"
#include "../../includes/reverse_iterator.hpp"
#include "../../includes/pair.hpp"

namespace ft {

template <	class Key,											// map::key_type
			class T,											// map::mapped_type
			class Compare = std::less<Key>,						// map::key_compare
			class Alloc = std::allocator<ft::pair<const Key, T> >	// map::allocator_type
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
	
	typedef typename ft::pair<const key_type, mapped_type>	value_type;
	typedef typename allocator_type::reference				reference;
	typedef typename allocator_type::const_reference		const_reference;
	typedef typename allocator_type::pointer				pointer;
	typedef typename allocator_type::const_pointer			const_pointer;
	
	typedef bidirectional_iterator<value_type>				iterator;
	typedef bidirectional_iterator<const value_type>	const_iterator;
	typedef reverse_iterator_wrap<iterator>					reverse_iterator;
	typedef reverse_iterator_wrap<const_iterator>			const_reverse_iterator;
	
	typedef std::ptrdiff_t	difference_type;
	typedef std::size_t		size_type;

	typedef node<value_type>	t_node;
	typedef	typename allocator_type::template rebind<t_node>::other	node_allocator;

	class value_compare : std::binary_function<value_type, value_type, bool> {
	protected:
		key_compare	comp;

	public:
		typedef bool		result_type;
		typedef value_type	first_argument_type;
		typedef value_type	second_argument_type;
		value_compare (key_compare c) : comp(c) {}
		bool operator() (const value_type & x, const value_type & y) const {
			return comp(x.first, y.first);
		}
	};

	/*
	 _____                         _           _ 
	/  __ \                       (_)         | |
	| /  \/ __ _ _ __   ___  _ __  _  ___ __ _| |
	| |    / _` | '_ \ / _ \| '_ \| |/ __/ _` | |
	| \__/\ (_| | | | | (_) | | | | | (_| (_| | |
	 \____/\__,_|_| |_|\___/|_| |_|_|\___\__,_|_| 
	*/

	// Constructs an empty map, with no elements
	explicit	map (const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type()) { // empty
		_root = NULL;
		_size = 0;
		_comp = comp;
		_alloc = alloc;
		_end = _empty_node();
		_rend = _empty_node();
	}

	// Constructs a map with as many elements as the range [first, last],
	// with each element constructed from its corresponding element
	// in that range, in the same order
	template < class InputIterator >
	map (InputIterator first, InputIterator last, const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type()) { // range
		_root = NULL;
		_size = 0;
		_comp = comp;
		_alloc = alloc;
		_end = _empty_node();
		_rend = _empty_node();
		while (first != last) {
			_add_one(*first);
			first++;
		}
	}

	// Constructs a map with a copy of each of the elements in x
	map (const map & x) { // copy
		_root = NULL;
		_size = 0;
		_comp = key_compare(x._comp);
		_alloc = allocator_type(x._alloc);
		_end = _empty_node();
		_rend = _empty_node();
		const_iterator src_it = x.begin();
		for (; src_it != x.end(); src_it++)
			_add_one(*src_it);
	}

	// This destroys all map elements, and deallocates all the storage capacity allocated by the map container
	// using its allocator
	~map () {
		_delete_tree();
		if (_end) {
			_alloc.destroy(_end);
			_alloc.deallocate(_end, 1);
			_end = NULL;
		}
		if (_rend) {
			_alloc.destroy(_rend);
			_alloc.deallocate(_rend, 1);
			_rend = NULL;
		}
	}

	// Assigns new contents to the container, replacing its current content and changing its size accordingly
	// The map preserves its current allocator, which is used to allocate additional storage if needed
	map &	operator= (const map & x) {
		_root = NULL;
		_size = 0;
		_comp = key_compare(x._comp);
		_alloc = allocator_type(x._alloc);
		_end = _empty_node();
		_rend = _empty_node();
		const_iterator src_it = x.begin();
		for (; src_it != x.end(); src_it++)
			_add_one(*src_it);
	
		return *this;
	}

	/*
	_____ _                 _                 
	|_   _| |               | |                
	| | | |_ ___ _ __ __ _| |_ ___  _ __ ___ 
	| | | __/ _ \ '__/ _` | __/ _ \| '__/ __|
	_| |_| ||  __/ | | (_| | || (_) | |  \__ \
	\___/ \__\___|_|  \__,_|\__\___/|_|  |___/
	*/

	// Returns an iterator reffering to the first element in the map container
	iterator		begin() {
		if (_size == 0)
			return (end());
		t_node *	tmp = _root;
		while (tmp && tmp->left)
			tmp = tmp->left;
		return iterator(tmp);
	}
	// If the map is const_qualified
	const_iterator	begin() const {
		if (_size == 0)
			return (end());
		t_node *	tmp = _root;
		while (tmp && tmp->left)
			tmp = tmp->left;
		return const_iterator(reinterpret_cast<node<const value_type> *>(tmp));
	}

	// Returns an iterator reffering to the past-the-end element in the map container
	iterator		end() {
		return iterator(_end);
	}
	// If the map is const_qualified
	const_iterator	end() const {
		return const_iterator(reinterpret_cast<node<const value_type> *>(_end));
	}

	// Returns a reverse_iterator reffering to the last element in the map container
	reverse_iterator		rbegin() {
		if (_size == 0)
			return (rend());
		return reverse_iterator(end());
	}
	// If the map is const_qualified
	const_reverse_iterator	rbegin() const {
		if (_size == 0)
			return (rend());
		return const_reverse_iterator(end());
	}

	// Returns a reverse iterator pointing to the theroritocal element preceding the 
	// first element in the map (which is considered its reverse end)
	reverse_iterator		rend() {
		return reverse_iterator(begin());
	}
	// If the map is const_qualified
	const_reverse_iterator	rend() const {
		return const_reverse_iterator(begin());
	}

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
		return (_size == 0);
	}

	// Returns the number of elements in the map container
	size_type	size () const {
		return _size;
	}

	// Returns the maximum number of elements that the map container can hold
	size_type	max_size () const {
		size_type	max_size = ~0;

		typename allocator_type::size_type	_alloc_size = _alloc.max_size();
		return (max_size > _alloc_size ? _alloc_size : max_size);
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
	mapped_type &	operator[] (const key_type & k) {
		t_node * found;

		if ((found = _search_node(_root, k)))
			return found->data.second;
		value_type	inserted = ft::make_pair(k, mapped_type());
		_add_one(inserted);
		found = _search_node(_root, k);
		return found->data.second;
	}

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
	// already in the container, and if so, the element is not inserted,
	// returning an iterator to this existing element
	pair<iterator, bool>	insert (const value_type & val) { // single element
		t_node * found;
		if ((found = _search_node(_root, val.first)))
			return ft::make_pair(iterator(found), false);
		_add_one(val);
		return ft::make_pair(iterator(_search_node(_root, val.first)), true);
	}
	iterator				insert (iterator position, const value_type & val) { // fill
		// TODO // Get info on hint
		// ? For now, ignoring hint and just adding value
		(void) position;
		t_node * found;
		if ((found = _search_node(_root, val.first)))
			return iterator(found);
		_add_one(val);
		return iterator(_search_node(_root, val.first));
	}
	// TODO Add enable if to protect from non iterators
	template < class InputIterator >
	void					insert (InputIterator first, InputIterator last) { // range
		while (first != last) {
			_add_one(*first);
			first++;
		}
	}

	// Removes from the map container either a single element of a range of elements
	// This effectively reduces the container size by the number of elements removed,
	// which are destroyed
	void		erase (iterator position) {
		_delete_one((*position).first);
	}
	size_type	erase (const key_type & k) {
		if (_search_node(_root, k)) {
			_delete_one(k);
			return 1;
		}
		return (0);
	}
	void		erase (iterator first, iterator last) {
		while (first != last) {
			_delete_one((*first).first);
			first++;
		}
	}

	// Exchanges the content of the container by the content of x, which is another map
	// of the same type; sizes may differ
	void	swap (map & x) {
		map	tmp(*this);

		clear();
		if (_end) {
			_alloc.destroy(_end);
			_alloc.deallocate(_end, 1);
			_end = NULL;
		}
		if (_rend) {
			_alloc.destroy(_rend);
			_alloc.deallocate(_rend, 1);
			_rend = NULL;
		}
		new (this) map(x);
	
		x.clear();

		if (x._end) {
			_alloc.destroy(x._end);
			_alloc.deallocate(x._end, 1);
			x._end = NULL;
		}
		if (x._rend) {
			_alloc.destroy(x._rend);
			_alloc.deallocate(x._rend, 1);
			x._rend = NULL;
		}
		x = tmp;
	}

	// Removes all elements from the map container (which are destroyed),
	// leaving the container with a size of 0
	void	clear () {
		_delete_tree();
	}

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
	key_compare	key_comp () const {
		return _comp;
	}

	// Returns a comparison object that can be used to compare two
	// elements to get whether the key of the first one goes before the second
	value_compare value_comp() const {
		return value_compare(_comp);
	}

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
	iterator		find (const key_type & k) {
		t_node * found;

		if ((found = _search_node(_root, k)))
			return iterator(found);
		return end();
	}
	const_iterator	find (const key_type & k) const {
		t_node * found;

		if ((found = _search_node(_root, k)))
			return iterator(found);
		return end();
	}

	// Search the container for elements with a key equivalent to k and
	// returns the number of matches
	// Because all elements in a map container are unique, the function can
	// only return 1 or 0
	size_type		count (const key_type & k) const {
		if (_search_node(_root, k))
			return 1;
		return 0;
	}

	// Returns an iterator pointing to the first element in the container
	// whose key is not considered to go before k (i.e., either it is equivalent
	// or goes after)
	iterator		lower_bound (const key_type & k) {
		t_node * tmp = _root;

		while (tmp && _comp(k, tmp->data.first))
			tmp = tmp->left;
		if (!tmp)
			return end();
		return iterator(tmp);
	}
	// If the map is const-qualified
	const_iterator	lower_bound (const key_type & k) const {
		t_node * tmp = _root;

		while (tmp && _comp(k, tmp->data.first))
			tmp = tmp->left;
		if (!tmp)
			return end();
		return const_iterator(tmp);	
	}

	// Returns an iterator pointing to the first element in the container
	// whose key is considered to go after k
	iterator		upper_bound (const key_type & k) {
		t_node * tmp = _root;

		while (tmp && !_comp(k, tmp->data.first))
			tmp = tmp->right;
		if (!tmp)
			return end();
		return iterator(tmp);
	}
	const_iterator	upper_bound (const key_type & k) const {
		t_node * tmp = _root;

		while (tmp && !_comp(k, tmp->data.first))
			tmp = tmp->right;
		if (!tmp)
			return end();
		return const_iterator(tmp);	
	}

	// Returns the bounds of a range that includes all the elements in the
	// container which have a key equivalent to k
	// Because the elements in a map container have unique keys, the range returned
	// will contain a single element at most
	pair<iterator, iterator>				equal_range (const key_type & k) {
		t_node * found;

		if ((found = _search_node(_root, k)))
			return ft::make_pair(lower_bound(k), upper_bound(k));
		return ft::make_pair(upper_bound(k), upper_bound(k));
	}
	pair<const_iterator, const_iterator>	equal_range (const key_type & k) const {
		t_node * found;
		
		if ((found = _search_node(_root, k)))
			return ft::make_pair(lower_bound(k), upper_bound(k));
		return ft::make_pair(upper_bound(k), upper_bound(k));
	}

	/*
	  ___  _ _                 _             
	 / _ \| | |               | |            
	/ /_\ \ | | ___   ___ __ _| |_ ___  _ __ 
	|  _  | | |/ _ \ / __/ _` | __/ _ \| '__|
	| | | | | | (_) | (_| (_| | || (_) | |   
	\_| |_/_|_|\___/ \___\__,_|\__\___/|_|         
	*/

	// Returns a copy of the allocator object associated with the map
	allocator_type	get_allocator () const {
		return _alloc_data;
	}

	// TO BE REMOVED
	void	display_tree(void) const {
		// DEBUG
		if (!_root)
			return ;
		_display_tree("", _root, false, (_root->right ? true : false));
		bool balanced = _is_balanced(_root);
		std::cout << "Is tree balanced ? " << (!balanced ? "No" : "Yes")  << std::endl;
	}

protected:

	/*
	 _   _           _             _   _            _                     _ 
	| | | |         | |           | | | |          | |                   | |
	| | | |_ __   __| | ___ _ __  | |_| |__   ___  | |__   ___   ___   __| |
	| | | | '_ \ / _` |/ _ \ '__| | __| '_ \ / _ \ | '_ \ / _ \ / _ \ / _` |
	| |_| | | | | (_| |  __/ |    | |_| | | |  __/ | | | | (_) | (_) | (_| |
	\___/|_| |_|\__,_|\___|_|     \__|_| |_|\___| |_| |_|\___/ \___/ \__,_|                            
	*/

	// to allocate storage
	node_allocator	_alloc;
	allocator_type	_alloc_data;
	// to sort the elements
	key_compare		_comp;
	// size of map
	size_type		_size;
	// root of binary tree
	t_node *		_root;

	t_node *		_end;
	t_node *		_rend;

	void	_add_one(const value_type & element) {
		if (_search_node(_root, element.first)) // no equal keys
			return ;
		_root = _add_node(NULL, _root, element);
		_end->parent = _get_max_node(_root);
		_rend->parent = _get_min_node(_root);
		_size++;
	}
	
	void	_delete_one(const key_type & key) {
		if (!_search_node(_root, key)) // if key doesnt exist in map
			return ;
		_root = _delete_node(_root, key);
		_end->parent = _get_max_node(_root);
		_rend->parent = _get_min_node(_root);
		_size--;
	}

	bool	_is_rightmost_node(t_node * _ptr) const {
		t_node *	tmp = _ptr;

		while (tmp && tmp->parent)
			tmp = tmp->parent;
		while (tmp && tmp->right)
			tmp = tmp->right;
		if (tmp == _ptr)
			return true;
		return false;
	}

	bool	_is_leftmost_node(t_node * _ptr) const {
		t_node *	tmp = _ptr;

		while (tmp && tmp->parent)
			tmp = tmp->parent;
		while (tmp && tmp->left)
			tmp = tmp->left;
		if (tmp == _ptr)
			return true;
		return false;
	}

	int _get_height(t_node *N) const { 
		if (N == NULL) 
			return 0; 
		return N->height; 
	} 

	int		_max(int a, int b) const {
		return (a > b)? a : b; 
	}

	bool		_is_balanced(t_node * node) const {
		if (!node)
			return true;
		if (abs(_get_balance(node)) <= 1 && _is_balanced(node->left) && _is_balanced(node->right))
			return true;
		return false;
	}

	int		_get_balance(t_node * node) const {
		if (!node || (!node->left && !node->right))
			return (0);
		if (!node->left)
			return -node->right->height;
		if (!node->right)
			return node->left->height;
		return node->left->height - node->right->height;
	}

	t_node *_right_rotation(t_node *x) 
	{ 
		t_node *y = x->left; 
		x->left = y->right; 

		if (y->right)
			y->right->parent = x;
		y->parent = x->parent;
		if (!x->parent)
			_root = y;
		else if (x == x->parent->right)
			x->parent->right = y;
		else
			x->parent->left = y;

		y->right = x; 
		x->parent = y;

		x->height = _max(_get_height(x->left), _get_height(x->right)) + 1;
		y->height = _max(_get_height(y->left), _get_height(y->right)) + 1;
	
		return y;
	}

	t_node *_left_rotation(t_node *x) 
	{ 
		t_node *y = x->right; 
		x->right = y->left;

		if (y->left)
			y->left->parent = x;
		y->parent = x->parent;
		if (!x->parent)
			_root = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;

		y->left = x; 
		x->parent = y;

		x->height = _max(_get_height(x->left), _get_height(x->right)) + 1; 
		y->height = _max(_get_height(y->left), _get_height(y->right)) + 1; 

		return y; 
	} 


	t_node *	_balance_tree(t_node * node, const value_type & val, bool delete_node) {
		node->height = 1 + _max(_get_height(node->left), _get_height(node->right));
		int balance = _get_balance(node);

		if (delete_node) {
			// Left Left Case
			if (balance > 1 && _get_balance(node->left) >= 0)
				return _right_rotation(node);
		
			// Left Right Case
			if (balance > 1 && _get_balance(node->left) < 0)
			{
				node->left = _left_rotation(node->left);
				return _right_rotation(node);
			}
		
			// Right Right Case
			if (balance < -1 && _get_balance(node->right) <= 0)
				return _left_rotation(node);
		
			// Right Left Case
			if (balance < -1 && _get_balance(node->right) > 0)
			{
				node->right = _right_rotation(node->right);
				return _left_rotation(node);
			}
		}
		else {
			// Left Left Case 
			if (balance > 1 && _comp(val.first, node->left->data.first)) 
				return _right_rotation(node); 

			// Right Right Case 
			if (balance < -1 && !_comp(val.first, node->right->data.first)) 
				return _left_rotation(node); 

			// Left Right Case 
			if (balance > 1 && !_comp(val.first, node->left->data.first)) 
			{ 
				node->left = _left_rotation(node->left); 
				return _right_rotation(node);
			}

			// Right Left Case 
			if (balance < -1 && _comp(val.first, node->right->data.first)) 
			{ 
				node->right = _right_rotation(node->right); 
				return _left_rotation(node); 
			}
		}

		return node;
	}

	t_node *	_empty_node() {
		t_node *	ret = _alloc.allocate(1);
		_alloc.construct(ret, t_node());
		ret->left = NULL;
		ret->right = NULL;
		ret->parent = NULL;
		ret->data = value_type();
		ret->height = 0;
		ret->_end = NULL;
		ret->_rend = NULL;
		return ret;
	}

	t_node * _new_node(const value_type & val, t_node * parent) {
		t_node *node = _alloc.allocate(1);
		_alloc.construct(node, t_node());
		node->left = NULL;
		node->right = NULL;
		node->parent = parent;
		node->data = val;
		node->height = 1;
		node->_end = _end;
		node->_rend = _rend;
		return node;
	}

	t_node *	_add_node(t_node * parent, t_node * node, const value_type & val) {
		if (!node)
			return _new_node(val, parent);
		if (_comp(val.first, node->data.first))
			node->left = _add_node(node, node->left, val);
		else if (!_comp(val.first, node->data.first))
			node->right = _add_node(node, node->right, val);
		return _balance_tree(node, val, false);
	}

	t_node * _get_min_node(t_node * node) const {
		t_node * current = node;
	
		/* loop down to find the leftmost leaf */
		while (current && current->left != NULL)
			current = current->left;
	
		return current;
	}

	t_node * _get_max_node(t_node * node) const {
		t_node * current = node;
	
		/* loop down to find the rightmost leaf */
		while (current && current->right != NULL)
			current = current->right;
	
		return current;
	}

	t_node *	_delete_node(t_node * node, const key_type & key) {
		t_node * tmp;
		if (!node)
			return node;
		else if (!_comp(key, node->data.first) && !_comp(node->data.first, key)) {
			if (!node->left && !node->right) {
				_alloc.destroy(node);
				_alloc.deallocate(node, 1);
				node = NULL;
			}
			else if (!node->left) {
				tmp = node;
				node = node->right;
				node->parent = tmp->parent;
				_alloc.destroy(tmp);
				_alloc.deallocate(tmp, 1);
				tmp = NULL;
			}
			else if (!node->right) {
				tmp = node;
				node = node->left;
				node->parent = tmp->parent;
				_alloc.destroy(tmp);
				_alloc.deallocate(tmp, 1);
				tmp = NULL;
			}
			else {
				tmp = _get_min_node(node->right);
				node->data = tmp->data;
				node->right = _delete_node(node->right, tmp->data.first);
			}
		}
		else if (_comp(key, node->data.first))
			node->left = _delete_node(node->left, key);
		else if (!_comp(key, node->data.first))
			node->right = _delete_node(node->right, key);
		if (!node)
			return node;
		return _balance_tree(node, node->data, true);
	}

	t_node *	_search_node(t_node * node, const key_type & val) const {
		if (!node)
			return (NULL);
		if (!_comp(val, node->data.first) && !_comp(node->data.first, val))
			return node;
		else if (_comp(val, node->data.first))
			return _search_node(node->left, val);
		else if (!_comp(val, node->data.first))
			return _search_node(node->right, val);
		return (NULL);
	}

	void	_delete_tree() {
		while (_root)
			_delete_one(_root->data.first);
	}

	void	_display_tree(const std::string & prefix, t_node * node, bool isLeft, bool childInRight) const {
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
};

}
