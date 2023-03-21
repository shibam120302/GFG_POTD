from typing import List


class Solution:
    def minimumTime(self, N : int, cur : int, pos : List[int], time : List[int]) -> int:
        mn=10**9
        for i in range(N):
            dist=abs(pos[i]-cur)
            mn=min(mn,dist*time[i])
        
        return mn
