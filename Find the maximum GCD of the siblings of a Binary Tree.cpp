class Solution {
    int ans, g;

    void solve(Node *root)
    {
        if(root==NULL)
        return;
        if(root->left!=NULL && root->right!=NULL)
        {
            int h=__gcd(root->left->data,root->right->data);
            if(h>g)
            {
                g=h;
                ans=root->data;
            }
            else if(h==g)
            {
                ans=max(ans,root->data);
            }
        }
        solve(root->left);
        solve(root->right);
    }

public:
    int maxGCD(Node* root) {
        ans = 0;
        g = 0;
        solve(root);
        return ans;
    }
};
