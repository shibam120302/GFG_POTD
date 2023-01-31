class Solution:
    # Function to check if a number  
    # is a substring of other or not 
    def issubstring(self, str2, rep):
        if str2 in rep:
            return True  # str2 is a Substring of rep
        return False     # not a substring
    
    def minRepeats(self, A, B):
        ans = 1
        S = A
        
        while len(S)<len(B):
            S += A 
            ans += 1 
            
        if self.issubstring(B,S):
            return ans 
        elif self.issubstring(B,S+A):
            return ans+1 
        else:
            return -1
