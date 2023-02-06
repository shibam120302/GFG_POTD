class Solution{
public:
    long long int res;
    Node *target_node;
    void down(Node *node,int direction){
        if(node){
            if(direction == 0)
                res += node->data;
            down(node->left, direction-1);
            down(node->right, direction+1);
        }
    }
    void find(Node *node,int target){
        if(target_node == NULL){
            if (node){
                if(node->data > target)
                    find(node->left, target);
                else if(node->data < target)
                    find(node->right, target);
                else{
                    target_node = node;
                    down(node, 0);
                }
            }
        }
    }
            
    long long int verticallyDownBST(Node *root,int target){
        
        res = -target;
        target_node = NULL;
        find(root, target);
        if(res == -target) return -1;
        return res;
    }
};
