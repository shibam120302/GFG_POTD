import math
class Solution:
    def minimumSquares(self, L, B):
        # code here
        x = math.gcd(L,B)
        return (L*B//(x*x), x)
