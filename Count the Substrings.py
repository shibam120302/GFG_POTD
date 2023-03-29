class Solution:
    def countSubstring(self, S): 
        ans=0
        for i in range(len(S)):
            c=0
            for j in range(i,len(S)):
                if ord(S[j])>=ord('a') and ord(S[j])<=ord('z'):
                    c+=1
                else:
                    c-=1
                if c==0:
                    ans+=1
        return ans
