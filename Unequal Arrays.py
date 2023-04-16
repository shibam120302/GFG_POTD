from typing import List
from collections import defaultdict
class Solution:
    def solve(self, N : int, A : List[int], B : List[int]) -> int:
        # code here
        ssum = 0
        ap = defaultdict(list)
        bp = defaultdict(list)
        for i in range(N):
            ssum += A[i] - B[i]
            ap[abs(A[i]) % 2].append(A[i])
            bp[abs(B[i]) % 2].append(B[i])
        
        if ssum != 0 or int(len(ap[0])) != int(len(bp[0])):
            return -1
        
        ans = 0
        for i in range(2):
            ap[i].sort()
            bp[i].sort()
            
            for j in range(len(ap[i])):
                ans += abs(ap[i][j] - bp[i][j]) // 2
            
        return ans // 2
