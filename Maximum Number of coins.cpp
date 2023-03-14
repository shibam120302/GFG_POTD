class Solution{
    public:
        int maxCoins(int N, vector <int> &a)
        {
            a.push_back(1);
            a.insert(a.begin(), 1);
            vector<vector<int> > dp(a.size(), vector<int>(a.size(), 0));
            for (int i = a.size() - 3; i >= 0; i --) {
                for (int j = i + 2; j < a.size();j ++) {
                    for (int k = i + 1; k < j; k ++)
                        dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + a[i] * a[k] * a[j]);
                }
            }
            return dp[0][a.size() - 1];    
        }
};
