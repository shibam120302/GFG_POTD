class Solution:
    def removeReverse(self, S): 
        #code here
        s=[]
        s[:0]=S 
        freq = [0]*26
        for i in s:
            freq[ord(i)-ord('a')]+=1
        l=0
        r=len(s)-1
        f=0
        while l<=r:
            if f==0:
                if freq[ord(s[l])-ord('a')]==1:
                    l+=1
                else:
                    freq[ord(s[l])-ord('a')]-=1
                    s[l]='#'
                    l+=1
                    f^=1
            else:
                if freq[ord(s[r])-ord('a')]==1:
                    r-=1
                else:
                    freq[ord(s[r])-ord('a')]-=1
                    s[r]='#'
                    r-=1
                    f^=1
        if f==1:
            s.reverse()
        ans=""
        for i in s:
            if i!='#':
                ans+=i
        return ans
