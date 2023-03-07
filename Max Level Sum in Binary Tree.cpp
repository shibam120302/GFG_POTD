class Solution{
  public:
    int maxLevelSum(Node *root) {
        // Base case
        if (root == NULL) return 0;
    
        // Initialize result
        int result = root->data;
    
        // Do Level order traversal keeping track of number
        // of nodes at every level.
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            // Get the size of queue when the level order
            // traversal for one level finishes
            int count = q.size();
    
            // Iterate for all the nodes in the queue currently
            int sum = 0;
            while (count--) {
                // Dequeue an node from queue
                Node *temp = q.front();
                q.pop();
    
                // Add this node's value to current sum.
                sum = sum + temp->data;
    
                // Enqueue left and right children of
                // dequeued node
                if (temp->left != NULL) q.push(temp->left);
                if (temp->right != NULL) q.push(temp->right);
            }
    
            // Update the maximum node count value
            result = max(sum, result);
        }
    
        return result;
    }

};
