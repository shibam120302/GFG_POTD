class Solution
{
    public:
    bool countSingleRec(Node* root, int &count)
{
	// Return false to indicate NULL
	if (root == NULL)
		return true;

	// Recursively count in left and right subtrees also
	bool left = countSingleRec(root->left, count);
	bool right = countSingleRec(root->right, count);

	// If any of the subtrees is not singly, then this
	// cannot be singly.
	if (left == false || right == false)
		return false;

	// If left subtree is singly and non-empty, but data
	// doesn't match
	if (root->left && root->data != root->left->data)
		return false;

	// Same for right subtree
	if (root->right && root->data != root->right->data)
		return false;

	// If none of the above conditions is true, then
	// tree rooted under root is single valued, increment
	// count and return true.
	count++;
	return true;
}

// This function mainly calls countSingleRec()
// after initializing count as 0
public:
int singlevalued(Node* root)
{
	// Initialize result
	int count = 0;

	// Recursive function to count
	countSingleRec(root, count);

	return count;
}
    
};
