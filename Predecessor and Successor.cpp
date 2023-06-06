class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
    	// Base case
    	if (root == NULL) return ;
    
    	// If key is present at root
    	if (root->key == key)
    	{
    		// the maximum value in left subtree is predecessor
    		if (root->left != NULL)
    		{
    			Node* tmp = root->left;
    			while (tmp->right)
    				tmp = tmp->right;
    			pre = tmp ;
    		}
    
    		// the minimum value in right subtree is successor
    		if (root->right != NULL)
    		{
    			Node* tmp = root->right ;
    			while (tmp->left)
    				tmp = tmp->left ;
    			suc = tmp ;
    		}
    		return ;
    	}
    
    	// If key is smaller than root's key, go to left subtree
    	if (root->key > key)
    	{
    		suc = root ;
    		findPreSuc(root->left, pre, suc, key) ;
    	}
    	else // go to right subtree
    	{
    		pre = root ;
    		findPreSuc(root->right, pre, suc, key) ;
    	}
    }
};
