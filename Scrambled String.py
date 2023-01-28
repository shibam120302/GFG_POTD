class Solution:
    def __init__(self):
        self.mp={}
    
    def isScramble(self,s1: str, s2: str):

        if s1==s2:
            return True
        if len(s1)!=len(s2):
            return False
        if s1+" "+s2 in self.mp:
            return self.mp[s1+" "+s2]
        n=len(s1)
        for i in range(1,n):
            if self.isScramble(s1[:i],s2[:i]) and self.isScramble(s1[i:],s2[i:]):
                self.mp[s1+" "+s2]=True
                return True
            elif self.isScramble(s1[:i],s2[n-i:]) and self.isScramble(s1[i:],s2[:n-i]):
                self.mp[s1+" "+s2]=True
                return True
        self.mp[s1+" "+s2]=False
        return False
