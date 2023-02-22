class Solution{
  
    public:
    void connect(Node *root)
    {
        // creating queue for level order traversal of tree
        queue <Node*> q;
        q.push(root);
        
        Node* prev=NULL;
        // prev hold the value of previous node on the particular level
        Node* end = root, *nextend;
        // end will hold value of last node of a level
        // and nextend will store the same for the next level
        
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
            if(temp->left) { q.push(temp->left); nextend = temp->left; }
            if(temp->right){ q.push(temp->right); nextend = temp->right; }
            // storing all available nodes and updating nextend
            
            if(prev) prev->nextRight = temp;
            // setting nextRight of previous node of that level
            
            if(temp == end)
            {
                // If we've reached the end of a level, we need to :
                // 1. Set nextRight of the node to NULL
                temp->nextRight = NULL;
                // 2. Make sure that it doesnt get connected to node of next level
                prev = NULL;
                // 3. Set the value of end for next level
                end = nextend;
            }
            // If not at end of a level, we need to make sure that 'prev' gets
            // the address of current node before we move to the next one
            else prev = temp;
        }
    }
    
};
