class Solution:
    def distinctColoring (self, N, r, g, b):
        # code here 
        dp= [[0 for i in range(3)] for j in range(N)]
        dp[0][0]=r[0]
        dp[0][1]=g[0]
        dp[0][2]=b[0]
        for i in range(1,N):
            dp[i][0]=r[i]+min(dp[i-1][1],dp[i-1][2])
            dp[i][1]=g[i]+min(dp[i-1][2],dp[i-1][0])
            dp[i][2]=b[i]+min(dp[i-1][0],dp[i-1][1])
            
        return min(dp[N-1][0],min(dp[N-1][1],dp[N-1][2]))
