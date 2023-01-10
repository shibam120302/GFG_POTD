class Solution {
  public:
    // Convert a given tree to a tree where  
    // every node contains sum of values of  
    // nodes in left and right subtrees in the original tree
    int toSumTreeUtil(Node *node)  
    {  
        // Base case  
        if(node == NULL)  
        return 0;  
      
        // Store the old value  
        int old_val = node->data;  
      
        // Recursively call for left and 
        // right subtrees and store the sum as  
        // new value of this node  
        node->data = toSumTreeUtil(node->left) + toSumTreeUtil(node->right);  
      
        // Return the sum of values of nodes 
        // in left and right subtrees and  
        // old_value of this node  
        return node->data + old_val;  
    } 
    
    void toSumTree(Node *node)
    {
        toSumTreeUtil(node);
    }
};
