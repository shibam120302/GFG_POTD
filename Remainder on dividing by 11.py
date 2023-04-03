class Solution:
    def xmod11(self,x):
        l = len(x)
        num = 0
        rem = 0
        for i in range(0,len(x)):
            num = rem*10 + int(x[i])
            rem = num % 11
            
        return rem
            
        
