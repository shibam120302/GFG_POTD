from typing import List

class Solution:
    def makeBeautiful(self, arr: List[int]) -> List[int]:
        # code here
        def check(a, b):
            return (a < 0 and b >= 0) or (a >= 0 and b < 0)
        
        st = []
        for i in range(len(arr)):
            if len(st) > 0 and check(st[-1], arr[i]):
                st.pop()
            else:
                st.append(arr[i])
        
        return st
