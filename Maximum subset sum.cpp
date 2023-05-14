
class Solution
{
    public:
    long long findMaxSubsetSum(int N, vector<int> &A)
    {
        long long dp[N+1][2];
        dp[0][0]=0,dp[0][1]=0;
        for(int i=1; i<=N; i++)
        {
            dp[i][0]=dp[i-1][1];
            dp[i][1]=max(dp[i-1][0]+A[i-1],dp[i-1][1]+A[i-1]);
        }
        return max(dp[N][0],dp[N][1]);
    }
};
