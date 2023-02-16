class Solution:
    def solve(self,idx,n,arr,dp):
        if idx>=n or idx<0:
            return 1
        if dp[idx]!=-1:
            return dp[idx]
        dp[idx]=0
        dp[idx]=self.solve(idx+arr[idx],n,arr,dp)
        return dp[idx]
        
    def goodStones(self, n, arr) -> int:
        dp=[-1]*(n)
        for i in range(n):
            self.solve(i,n,arr,dp)
        return sum(dp)
