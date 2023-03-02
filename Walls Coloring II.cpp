class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        if (n == 0) return 0;
        int k = costs[0].size();
        if (k == 0) return 0;
        // Stores the first minimum value
        int min1 = INT_MAX;
        // Stores the second most minimum value
        int min2 = INT_MAX;
        // Creating a dp 2D array of size n*k
        vector<vector<int>> dp(n, vector<int>(k));
        for (int i = 0; i < k; i++) {
            dp[0][i] = costs[0][i];
            if (costs[0][i] < min1) {
                min2 = min1;
                min1 = costs[0][i];
            } else if (costs[0][i] < min2) {
                min2 = costs[0][i];
            }
        }
        if (n == 1) {
            return min1;
        }
        // Stores the current minimum value in a given iteration
        int cmin1 = INT_MAX;
        // Stores the second most current minimum value in a given iteration
        int cmin2 = INT_MAX;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < k; j++) {
                if (dp[i - 1][j] != min1) {
                    dp[i][j] = costs[i][j] + min1;
                }
                else {
                    dp[i][j] = costs[i][j] + min2;
                }
                    
                if (dp[i][j] < cmin1) {
                    cmin2 = cmin1;
                    cmin1 = dp[i][j];
                } 
                else if (dp[i][j] < cmin2) {
                    cmin2 = dp[i][j];
                }
            }
            min1 = cmin1;
            min2 = cmin2;
            cmin1 = INT_MAX;
            cmin2 = INT_MAX;
        }
        // If min1 value is less than 0, implies the answer is not possible
        if (min1 < 0) {
            return -1;
            
        }
        return min1;
    }
};
