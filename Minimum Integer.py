from typing import List


class Solution:
    def minimumInteger(self, N : int, A : List[int]) -> int:
        # code here
        sumo = sum(A)
        ans = 10**9
        for x in A:
            if N*x >= sumo:
                ans = min(ans, x)
        return ans
        
