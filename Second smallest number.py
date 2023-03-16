class Solution:
    def secondSmallest(self, S, D):
        if(S>=D*9 or S==1 or D==1):
            return "-1"
        
        dup = D
        
        S -= 1
        ans = ""
        for i in range(D-1, 0, -1):
            if(S>9):
                ans += str(9)
                S -= 9
            else:
                ans += str(S)
                S = 0
        
        ans += str(S+1)
        ans = ans[::-1]
        
        ind = dup-1
        for i in range(dup-1, -1, -1):
            if(ans[i]=='9'):
                ind = i
            else:
                break
        
        ans = list(ans)
        ans[ind] = str(int(ans[ind])-1)
        ans[ind-1] = str(int(ans[ind-1])+1)
        
        ans = "".join(ans)
        
        return ans
