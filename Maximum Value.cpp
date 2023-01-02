class Solution {
  public:
    void solve(Node* node,int level,vector<int> &answer)
    {
        if(node==NULL)
            return ;
        if(level==answer.size())
            answer.push_back(node->data);
        else
            answer[level]=max(answer[level],node->data);
        solve(node->left,level+1,answer);
        solve(node->right,level+1,answer);
    }
    
    vector<int> maximumValue(Node* node) {
       vector<int> answer;
       solve(node,0,answer);
       return answer;
    }
};
