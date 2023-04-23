class Solution:
    def minimumNumber(self, n, arr):
        #code here
        def gcd(a,b):
            if b == 0:
                return a
            return gcd(b, a%b)
        
        res=0
        for i in range(n):
            res = gcd(res, arr[i])
        return re
