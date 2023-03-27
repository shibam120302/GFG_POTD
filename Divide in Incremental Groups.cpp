class Solution {
    

  public:
    // Function to count the number
    // of ways to divide the number N
    // in groups such that each group
    // has K number of elements
    int calculate(int pos, int prev, int left, int K,
                  vector<vector<vector<int>>> &dp) {
        // Base Case
        if (pos == K) {
            if (left == 0)
                return 1;
            else
                return 0;
        }
        // if N is divides completely
        // into less than K groups
        if (left == 0) return 0;

        // If the subproblem has been
        // solved, use the value
        if (dp[pos][prev][left] != -1) return dp[pos][prev][left];

        int answer = 0;
        // put all possible values
        // greater equal to prev
        for (int i = prev; i <= left; i++) {
            answer += calculate(pos + 1, i, left - i, K, dp);
    
        }

        return dp[pos][prev][left] = answer;
    }

    // Function to count the number of
    // ways to divide the number N in groups
    int countWaystoDivide(int N, int K) {
        // Intialize DP Table as -1
        vector<vector<vector<int>>> dp(
            K + 1, vector<vector<int>>(N + 1, vector<int>(N + 1, -1)));

        return calculate(0, 1, N, K, dp);
    }
};
