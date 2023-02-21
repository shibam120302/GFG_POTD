class Solution:
    def minIteration(self, N, M, x, y):
        #code here
        ans=0
        for i in range(1,N+1):
            for j in range(1,M+1):
                ans=max(ans,abs(x-i)+abs(y-j))
        return ans
