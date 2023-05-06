#include "BSTs.c" // your student number

void test_newBST_Node()
{
	// 1.1: creating and initializing a new node
	BST_Node *expected = NULL;
	BST_Node *actual = NULL;
	
	expected = (BST_Node *)calloc(1, sizeof(BST_Node));
	expected->freq = -1.0;
	expected->bar = -1;
	expected->index = -1.0;
	expected->key = (10.0*expected->bar)+expected->index;
	expected->left = NULL;
	expected->right = NULL;
	
	actual = newBST_Node(-1.0, -1, -1.0);
	
	if (expected->freq == actual->freq &&
		expected->bar == actual->bar &&
		expected->index == actual->index &&
		expected->key == actual->key &&
		actual->left == NULL &&
		actual->right == NULL)
	{
		printf("1.1:  PASSED\n");
	}
	else
	{
		printf("1.1: FAILED\n");
		printf("freq: %s", expected->freq == actual->freq ? " GOOD\n" : "FAILED\n");
		printf("bar: %s", expected->bar == actual->bar ? "  GOOD\n" : "FAILED\n");
		printf("index: %s", expected->index == actual->index ? "GOOD\n" : "FAILED\n");
		printf("key: %s", expected->key == actual->key ? "  GOOD\n" : "FAILED\n");
		printf("left: %s", actual->left == NULL ? " GOOD\n" : "FAILED\n");
		printf("right: %s", actual->right == NULL ? "GOOD\n\n" : "FAILED\n\n");
	}
	
	printf("\n");
	return;
}

BST_Node* search_n(BST_Node* root, double key)
{
	// this function is used in test 2
	// this function returns the address of the node that contains key
	// if key is not found, this function returns NULL
    if (root == NULL)
    {
        return NULL;
    }

    if (key == root->key)
    {
        return root;
    }

    if (key <= root->key)
    {
        return search_n(root->left, key);
    }
    else
    {
        return search_n(root->right, key);
    }
}

int length(BST_Node* root)
{
	// this function is used in test 2.5 and calculates the size of a BST
	if (root==NULL)
	{
		return 0;
	}
	else 
	{
		return(length(root->left) + 1 + length(root->right)); 
	}		
}

void test_BST_insert()
{
	// 2.1: empty tree
	// 2.2: inserting to the left of the root
	// 2.3: inserting to the right of the root
	// 2.41: inserting at the bottom left
	// 2.42: inserting at the bottom right
	// 2.5: inserting a duplicate
	// 2.6: null new node
	
	BST_Node* root = NULL;
	BST_Node* new_node = newBST_Node(1.2, 1, 13);
	
	int old_size = 0;
	int size = 0;
	
	double key = new_node->key;
	
	// 2.1
	root = BST_insert(root, new_node);
	// size: 1
	printf("2.1: %s", root == new_node && length(root) == 1 ? " PASSED\n" : " FAILED\n");
	
	// 2.2
	new_node = newBST_Node(1.2, 1, 3);
	root = BST_insert(root, new_node);
	// size: 2
	printf("2.2: %s", root->left == new_node && length(root) == 2 ? " PASSED\n" : " FAILED\n");
	
	// 2.3
	new_node = newBST_Node(1.2, 1, 19);
	root = BST_insert(root, new_node);
	// size: 3
	printf("2.3: %s", root->right == new_node && length(root) == 3 ? " PASSED\n" : " FAILED\n");
	
	// 2.4
	new_node = newBST_Node(1.2, 1, 1);
	root = BST_insert(root, new_node);
	// size: 4
	printf("2.41: %s", root->left->left == new_node && length(root) == 4 ? "PASSED\n" : " FAILED\n");
	
	new_node = newBST_Node(1.2, 1, 5);
	root = BST_insert(root, new_node);
	// size: 5
	printf("2.42: %s", root->left->right == new_node && length(root) == 5 ? "PASSED\n" : " FAILED\n");
	
	// 2.5
	// inserting more nodes
	new_node = newBST_Node(1.2, 1, 16);
	root = BST_insert(root, new_node);
	new_node = newBST_Node(1.2, 1, 25);
	root = BST_insert(root, new_node);
	
	old_size = length(root);
	new_node = newBST_Node(1.2, 1, 25); // should not insert
	root = BST_insert(root, new_node);
	size = length(root);
	printf("2.5: %s", old_size == size ? " PASSED\n" : " FAILED\n");
	
	// 2.6
	new_node = NULL;
	old_size = length(root);
	root = BST_insert(root, new_node);
	size = length(root);
	printf("2.6: %s", old_size == size ? " PASSED\n" : " FAILED\n");
	
	printf("\n");
	return;
}

void test_BST_search()
{
	// 3.1: empty tree
	// 3.2: one node, found
	// 3.3: one node, not found
	// 3.4: normal tree, value found at the middle
	// 3.5: normal tree, value found at the right end
	// 3.6: normal tree, value found at the left end
	// 3.7: normal tree, value not found
	
	BST_Node* new_root = NULL;
	BST_Node* new_node = NULL;
	
	// 3.1
	printf("3.1: %s", BST_search(new_root, 1, 2) == NULL ? " PASSED\n" : " FAILED\n");
	
	// 3.2
	new_root = newBST_Node(1.2, 1, 3);
	new_node = newBST_Node(1.2, 1, 1);
	
	new_root = BST_insert(new_root, new_node);
	printf("3.2: %s", BST_search(new_root, 1, 1) == new_root->left ? " PASSED\n" : " FAILED\n");
	
	// 3.3
	printf("3.3: %s", BST_search(new_root, 1, 1.1) == NULL ? " PASSED\n" : " FAILED\n");
	
	// 3.4
	new_node = newBST_Node(1.2, 1, 6);
	new_root = BST_insert(new_root, new_node);
	
	new_node = newBST_Node(1.2, 1, 0);
	new_root = BST_insert(new_root, new_node);
	
	new_node = newBST_Node(1.2, 1, 2);
	new_root = BST_insert(new_root, new_node);
	
	new_node = newBST_Node(1.2, 1, 5);
	new_root = BST_insert(new_root, new_node);
	
	new_node = newBST_Node(1.2, 1, 7);
	new_root = BST_insert(new_root, new_node);
	
	printf("3.4: %s", BST_search(new_root, 1, 1) == new_root->left ? " PASSED\n" : " FAILED\n");
	
	// 3.5
	printf("3.5: %s", BST_search(new_root, 1, 7) == new_root->right->right ? " PASSED\n" : " FAILED\n");
	
	// 3.6
	printf("3.6: %s", BST_search(new_root, 1, 0) == new_root->left->left ? " PASSED\n" : " FAILED\n");
	
	// 3.7
	printf("3.7: %s", BST_search(new_root, 1, 2.1) == NULL ? " PASSED\n" : " FAILED\n");
	
	printf("\n");
	return;
}

void test_find_successor()
{
	// 4.1: empty tree
	// 4.2: no nodes to the left
	// 4.3: one node to the left
	// 4.4: multiple nodes to the left
	
	BST_Node* new_node = NULL;
	
	// 4.1
	printf("4.1: %s", find_successor(NULL) == NULL ? " PASSED\n" : " FAILED\n");
	
	// building the tree
	BST_Node* root = newBST_Node(1.2, 1, 13);
	
	// 13
	new_node = newBST_Node(1.2, 1, 3);
	root = BST_insert(root, new_node);
	
	// 11
	new_node = newBST_Node(1.2, 1, 1);
	root = BST_insert(root, new_node);
	
	// 15
	new_node = newBST_Node(1.2, 1, 5);
	root = BST_insert(root, new_node);
	
	// 29
	new_node = newBST_Node(1.2, 1, 19);
	root = BST_insert(root, new_node);
	
	// 26
	new_node = newBST_Node(1.2, 1, 16);
	root = BST_insert(root, new_node);
	
	// 35
	new_node = newBST_Node(1.2, 1, 25);
	root = BST_insert(root, new_node);
	
	// 4.2
	printf("4.2: %s", find_successor(root->right->right) == root->right->right ? " PASSED\n" : " FAILED\n");
	
	// 4.3
	printf("4.3: %s", find_successor(root->right) == root->right->left ? " PASSED\n" : " FAILED\n");
	
	// 4.4
	new_node = newBST_Node(1.2, 1, 15);
	root = BST_insert(root, new_node);
	printf("4.4: %s", find_successor(root->right) == root->right->left->left ? " PASSED\n" : " FAILED\n");
	printf("\n");
}

void test_BST_delete()
{
	// 5.1: Deleting from an empty tree
	// 5.2: Deleting from a tree that has one node
	// 5.3: Deleting a node that has no children
	// 5.31: For funzies - Reinserting the node that we deleted
	// 5.4: Deleting a node that has one child at the left
	// 5.5: Deleting a node that has one child at the right
	// 5.6: Deleting a node that has 2 children
	// 5.7: Deleting the root
	// 5.8: Deleting a key not in the tree
	
	BST_Node* root = NULL;
	BST_Node* new_node = NULL;
	
	// 5.1
	root = BST_delete(root, 1, 0.2);
	printf("5.1: %s", root == NULL ? " PASSED\n" : " FAILED\n");
	
	// 5.2
	root = newBST_Node(1, 1, 10.25);
	root = BST_delete(root, 1, 10.25);
	printf("5.2: %s", root == NULL && length(root) == 0 ? " PASSED\n" : " FAILED\n");
	
	// building the tree
	root = newBST_Node(1, 1, 10.25);
	new_node = newBST_Node(1, 1, 10);
	root = BST_insert(root, new_node);
	
	new_node = newBST_Node(1, 1, 0.75);
	root = BST_insert(root, new_node);
	
	new_node = newBST_Node(1, 1, 10.15);
	root = BST_insert(root, new_node);
	
	new_node = newBST_Node(1, 1, 0.95);
	root = BST_insert(root, new_node);
	
	new_node = newBST_Node(1, 1, 10.5); // we are going to delete this in 5.3
	root = BST_insert(root, new_node);
	
	// 5.3: delete 20.5
	root = BST_delete(root, 1, 10.5);
	printf("5.3: %s", BST_search(root, 1, 10.5) == NULL && root->right == NULL && length(root) == 5 ? " PASSED\n" : " FAILED\n");
	
	// 5.31: reinsert 20.5
	new_node = newBST_Node(1, 1, 10.5); // we are going to reinsert the node we deleted
	root = BST_insert(root, new_node);
	printf("5.31: %s", root->right == new_node && length(root) == 6 ? "PASSED\n" : " FAILED\n");
	
	new_node = newBST_Node(1, 1, 10.4); 
	root = BST_insert(root, new_node);
	
	// 5.4: delete 20.4
	root = BST_delete(root, 1, 10.4);
	printf("5.4: %s", BST_search(root, 1, 10.4) == NULL && root->right->left == NULL && length(root) == 6 ? " PASSED\n" : " FAILED\n");
	
	// 5.5: delete 10.95
	root = BST_delete(root, 1, 0.95);
	printf("5.5: %s", BST_search(root, 1, 0.95) == NULL && root->left->left->right == NULL && length(root) == 5 ? " PASSED\n" : " FAILED\n");
	
	// 5.6: delete 20.0 (I feel like this test is a bit wonky)
	root = BST_delete(root, 1, 10);
	printf("5.6: %s", BST_search(root, 1, 20.0) == NULL && length(root) == 4 ? " PASSED\n" : " FAILED\n");
	
	// 5.7: delete the root (I feel like this test is a bit wonky)
	root = BST_delete(root, 1, 10.25);
	printf("5.7: %s", BST_search(root, 1, 20.25) == NULL && length(root) == 3 ? " PASSED\n" : " FAILED\n");
	
	int old_length = length(root);
	root = BST_delete(root, 1, 1000);
	int new_length = length(root);
	printf("5.8: %s", old_length == new_length ? " PASSED\n" : " FAILED\n");
}

int main()
{
	test_newBST_Node();
	test_BST_insert();
	test_BST_search();
	test_find_successor();
	test_BST_delete();
}