class Solution{
public:
    Node *search(Node *root,int target,int &ans){
        if(root==NULL) return NULL;
        if(root->data==target){
            return root;
        }
        ans+=root->data;
        if(target>root->data){
            return search(root->right,target,ans);
        }
        return search(root->left,target,ans);
    }
    int dfs(Node *node){
        int res=node->data;
        int mn=1e9;
        if(node->left) mn=min(mn,dfs(node->left));
        if(node->right) mn=min(mn,dfs(node->right));
        if(mn==1e9) return res;
        return res+mn;
    }
    int maxDifferenceBST(Node *root,int target){
        int ans=0;
        Node *node=search(root,target,ans);
        if(node==NULL) return -1;
        ans-=dfs(node)-node->data;
        return ans;
    }
};
