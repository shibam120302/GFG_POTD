class Solution:
    def maxLength(self,arr,n):
        pos = 0
        neg = 0
        ans = 0
        
        for i in range(n):
            if arr[i] == 0:
                pos,neg = 0,0
            elif arr[i] > 0 :
                pos+=1
                if neg > 0:
                    neg+=1
            else:
                temp = pos
                if neg > 0:
                    pos = neg + 1
                else:
                    pos = 0
                neg = temp + 1
            ans = max(ans,pos)
        return ans
