class trieNode:
    def __init__(self):
        self.char=[None]*(26)
class Trie:
    def __init__(self):
        self.root=trieNode()
    def insert(self,a):
        curr=self.root
        for el in a:
            if curr.char[ord(el)-ord("a")]==None:
                curr.char[ord(el)-ord("a")]=trieNode()
            curr=curr.char[ord(el)-ord("a")]
    def find(self,a):
        curr=self.root
        for el in a:
            if curr.char[ord(el)-ord("a")] is None:
                return 0
            curr=curr.char[ord(el)-ord("a")]
        return 1
                
                
        
class Solution:
    def prefixSuffixString(self, s1, s2) -> int:
        p=Trie()
        for el in s1:
            p.insert(el)
            p.insert(el[::-1])
        ans=0
        for el in s2:
            if p.find(el) or p.find(el[::-1]):
                ans+=1
            
        return ans
        
        
        
        
