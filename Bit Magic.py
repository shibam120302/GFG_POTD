class Solution:
    def bitMagic(self,n,arr):
        c=0
        for i in range(n):
            if arr[i]!=arr[n-i-1]:
                c+=1
        c//=2
        return (c+1)//2
    
