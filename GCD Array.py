from typing import List
class Solution:
    def solve(self, N : int, K : int, arr : List[int]) -> int:
        # code here
        total = sum(arr)
        divisors = []
        m = int(total ** 0.5)
        for i in range(1, m+1):
            if total % i == 0:
                divisors.append(i)
                if i != (total // i):
                    divisors.append(total // i)
        
        divisors.sort(reverse = True)
        for i in range(1, N):
            arr[i] += arr[i-1]
        
        out = 1
        for x in divisors:
            cnt = 0
            for y in arr:
                if (y % x == 0):
                    cnt += 1
            
            if cnt >= K:
                out = x
                break
        
        return out
