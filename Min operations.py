class Solution:
    def solve(self, a : int, b : int) -> int:
        # code here
        if a == b:
            return 0
        elif a&b == min(a,b):
            return 1
        else:
            return 2
