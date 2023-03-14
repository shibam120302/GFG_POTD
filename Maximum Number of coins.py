class Solution():
    def maxCoins(self, N, a):
            a.append(1)
            a.insert(0, 1)
            n = len(a)
            dp = [[0 for i in range(n)] for j in range(n)]
            for i in range(n-3,-1,-1):
                for j in range(i+2,n):
                    for k in range(i+1,j):
                        dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + a[i] * a[k] * a[j])

            return dp[0][n - 1]
