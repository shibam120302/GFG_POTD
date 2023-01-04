from typing import List

maxi = 10**5+2
class Solution:
    def maximum_profit(self, n : int, intervals : List[List[int]]) -> int:
        intervals.sort(key = lambda x:x[1])
        
        dp = [0]*maxi
        
        ind = 0
        i = 1
        while i < maxi:
            dp[i] = max(dp[i], dp[i-1])
            if ind < n and intervals[ind][1] == i:
                st, en, val = intervals[ind]
                dp[i] = max(dp[i], dp[st]+val)
                ind += 1
                continue
            i += 1
        return dp[maxi-1]
