class Solution:
    def minVal(self, a, b):
        setBits=str(bin(b)).count("1")
        setBits1=str(bin(a)).count("1")
        ans = 0
        for i in range(32):
            mask=1<<i
            set=a&mask
            if set==0 and setBits>setBits1:
                ans|=mask
                setBits-=1
            elif set!=0 and setBits1>setBits:
                setBits1-=1
            else:
                ans|=set
        return ans
