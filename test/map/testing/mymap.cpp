// C++ program to insert a node in AVL tree 
#include<bits/stdc++.h>
using namespace std;

// An AVL tree node 
class t_node 
{ 
    public:
    int key; 
    t_node *left; 
    t_node *right; 
    int height; 
}; 

// A utility function to get the 
// height of the tree 
int height(t_node *N)
{ 
    if (N == NULL) 
        return 0; 
    return N->height; 
}

// A utility function to get maximum
// of two integers 
int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 

/* Helper function that allocates a 
   new node with the given key and 
   NULL left and right pointers. */
t_node * newNode(int key) 
{ 
    t_node * node = new t_node();
    node->key = key; 
    node->left = NULL; 
    node->right = NULL; 
    node->height = 1; // new node is initially
                      // added at leaf 
    return(node); 
} 

// A utility function to right
// rotate subtree rooted with y 
// See the diagram given above. 
t_node *rightRotate(t_node *y) 
{ 
    t_node *x = y->left; 
    t_node *T2 = x->right; 

    // Perform rotation 
    x->right = y; 
    y->left = T2; 

    // Update heights 
    y->height = max(height(y->left), height(y->right)) + 1; 
    x->height = max(height(x->left), height(x->right)) + 1; 

    // Return new root 
    return x; 
} 

// A utility function to left 
// rotate subtree rooted with x 
// See the diagram given above. 
t_node *leftRotate(t_node *x) 
{ 
    t_node *y = x->right; 
    t_node *T2 = y->left; 

    // Perform rotation 
    y->left = x; 
    x->right = T2; 

    // Update heights 
    x->height = max(height(x->left), height(x->right)) + 1; 
    y->height = max(height(y->left), height(y->right)) + 1; 

    // Return new root 
    return y; 
} 

// Get Balance factor of node N 
int		_get_balance(t_node * _node) {
	if (!_node || (!_node->left && !_node->right))
		return (0);
	if (!_node->left)
		return -_node->right->height;
	if (!_node->right)
		return _node->left->height;
	return _node->left->height - _node->right->height;
}

// Recursive function to insert a key
// in the subtree rooted with node and
// returns the new root of the subtree. 
t_node * insert(t_node * node, int key) 
{ 
    /* 1. Perform the normal BST insertion */
    if (node == NULL) 
        return(newNode(key)); 

    if (key < node->key) 
        node->left = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key); 
    else // Equal keys are not allowed in BST 
        return node; 

    /* 2. Update height of this ancestor t_node */
    node->height = 1 + max(height(node->left), 
                        height(node->right)); 

    /* 3. Get the balance factor of this ancestor 
        node to check whether this node became 
        unbalanced */
    int balance = _get_balance(node); 

    // If this node becomes unbalanced, then 
    // there are 4 cases 

    // Left Left Case 
    if (balance > 1 && key < node->left->key) 
        return rightRotate(node); 

    // Right Right Case 
    if (balance < -1 && key > node->right->key) 
        return leftRotate(node); 

    // Left Right Case 
    if (balance > 1 && key > node->left->key) 
    { 
        node->left = leftRotate(node->left); 
        return rightRotate(node); 
    } 

    // Right Left Case 
    if (balance < -1 && key < node->right->key) 
    { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 

    /* return the (unchanged) node pointer */
    return node; 
} 

/* Given a non-empty binary search tree, 
return the node with minimum key value 
found in that tree. Note that the entire 
tree does not need to be searched. */
t_node * minValueNode(t_node * node) 
{ 
    t_node * current = node; 

    /* loop down to find the leftmost leaf */
    while (current->left != NULL) 
        current = current->left; 

    return current; 
} 

// Recursive function to delete a node 
// with given key from subtree with 
// given root. It returns root of the 
// modified subtree. 
t_node * deleteNode(t_node * root, int key) 
{ 
    
    // STEP 1: PERFORM STANDARD BST DELETE 
    if (root == NULL) 
        return root; 

    // If the key to be deleted is smaller 
    // than the root's key, then it lies
    // in left subtree 
    if ( key < root->key ) 
        root->left = deleteNode(root->left, key); 

    // If the key to be deleted is greater 
    // than the root's key, then it lies 
    // in right subtree 
    else if( key > root->key ) 
        root->right = deleteNode(root->right, key); 

    // if key is same as root's key, then 
    // This is the node to be deleted 
    else
    { 
        // node with only one child or no child 
        if( (root->left == NULL) ||
            (root->right == NULL) ) 
        { 
            t_node *temp = root->left ? 
                         root->left : 
                         root->right; 

            // No child case 
            if (temp == NULL) 
            { 
                temp = root; 
                root = NULL; 
            } 
            else // One child case 
            *root = *temp; // Copy the contents of 
                           // the non-empty child 
            free(temp); 
        } 
        else
        { 
            // node with two children: Get the inorder 
            // successor (smallest in the right subtree) 
            t_node * temp = minValueNode(root->right); 

            // Copy the inorder successor's 
            // data to this node 
            root->key = temp->key; 

            // Delete the inorder successor 
            root->right = deleteNode(root->right, 
                                     temp->key); 
        } 
    } 

    // If the tree had only one node
    // then return 
    if (root == NULL) 
    return root; 

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE 
    root->height = 1 + max(height(root->left), 
                           height(root->right)); 

    // STEP 3: GET THE BALANCE FACTOR OF 
    // THIS NODE (to check whether this 
    // node became unbalanced) 
    int balance = _get_balance(root); 

    // If this node becomes unbalanced, 
    // then there are 4 cases 

    // Left Left Case 
    if (balance > 1 && 
        _get_balance(root->left) >= 0) 
        return rightRotate(root); 

    // Left Right Case 
    if (balance > 1 && 
        _get_balance(root->left) < 0) 
    { 
        root->left = leftRotate(root->left); 
        return rightRotate(root); 
    } 

    // Right Right Case 
    if (balance < -1 && 
        _get_balance(root->right) <= 0) 
        return leftRotate(root); 

    // Right Left Case 
    if (balance < -1 && 
        _get_balance(root->right) > 0) 
    { 
        root->right = rightRotate(root->right); 
        return leftRotate(root); 
    } 

    return root; 
} 



bool		_is_balanced(t_node * _node) {
	if (!_node)
		return true;
	if (abs(_get_balance(_node)) <= 1 && _is_balanced(_node->left) && _is_balanced(_node->right))
		return true;
	return false;
}

void	_display_tree(const std::string & prefix, t_node * _node, bool isLeft, bool childInRight) {
	if (_node) {
		std::cout << prefix;
		std::cout << (isLeft && childInRight ? "├──" : "└──");
		std::cout << (isLeft ? "\e[34m" : "\e[31m");
		std::cout << _node->key << std::endl;
		std::cout << "\e[0m";
		_display_tree(prefix + (isLeft && childInRight ? "│   " : "    "), _node->left, true, (_node->right ? true : false));
		_display_tree(prefix + (isLeft && childInRight ? "│   " : "    "), _node->right, false, (_node->right ? true : false));
	}
}

#include <random>
#include <time.h>
// Driver Code
int main() 
{ 
    t_node *root = NULL; 
    
    /* Constructing tree given in 
    the above figure */
    // root = insert(root, 60); 
    // root = insert(root, 25); 
    // root = insert(root, 68); 
    // root = insert(root, 73); 
    // root = insert(root, 20); 
    // root = insert(root, 45); 
    // root = insert(root, 7); 
    // root = insert(root, 34); 
    // root = insert(root, 50); 
    // root = insert(root, 32);

	srand(time(NULL));
	for (int i = 0; i < 150; i++) {
		root = insert(root, i);
	}

	_display_tree("", root, false, (root->right ? true : false));
	// cout << "is tree balanced ? " << (_is_balanced(root) ? "Yes" : "No") << endl;
    // root = deleteNode(root, 25);
    // cout << "is tree balanced ? " << (_is_balanced(root) ? "Yes" : "No") << endl;
   	// root = deleteNode(root, 50);
    // cout << "is tree balanced ? " << (_is_balanced(root) ? "Yes" : "No") << endl;
    // root = deleteNode(root, 100);
    // cout << "is tree balanced ? " << (_is_balanced(root) ? "Yes" : "No") << endl;
    // root = deleteNode(root, 125);
    // cout << "is tree balanced ? " << (_is_balanced(root) ? "Yes" : "No") << endl;
	for (int i = 0; i < 150; i++) {
		root = deleteNode(root, i);
	}
	_display_tree("", root, false, (root->right ? true : false));
    
	// _display_tree("", root, false, (root->right ? true : false));
    return 0; 
}
