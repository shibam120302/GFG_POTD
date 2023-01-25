class Solution:
    def minOperation(self, s): 
        n = len(s)
        for i in range (n // 2 - 1, -1, -1):
            if(s[0 : i + 1] == s[i + 1 : 2 * (i + 1)]):
                return (i + 1) + 1 + (n - 2 * (i + 1))
        return n
