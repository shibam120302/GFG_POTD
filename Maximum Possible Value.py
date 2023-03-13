class Solution:
    def maxPossibleValue(self, N, A, B): 
        ans = 0
        tot = 0
        mn = 10**9
        for i in range(N):
            x=A[i]
            y=B[i]
            if(y%2):
                y-=1
            if(y>=2):
                mn=min(mn,x)
            ans+=y*x
            tot+=y;
        if(tot%4!=0):
           ans-=2*mn
        return ans
