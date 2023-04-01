
class Solution:
    def minOperations(self, N):
        ans = N//2
        ans *= (N+1)//2
        return ans
