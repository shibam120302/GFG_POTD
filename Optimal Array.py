from typing import List
class Solution:
    def optimalArray(self, n : int, a : List[int]) -> List[int]:
        sum1=0
        sum2=0
        ans=[]
        mid=(n+1)//2
        for i in range(mid):
            sum1+=a[i]
            if 2*i<n:
                sum2+=a[2*i]
                diff=((i+1)*a[i])-sum1+((sum2-sum1)-i*a[i])
                ans.append(diff)
            if 2*i+1<n:
                sum2+=a[2*i+1]
                diff=((i+1)*a[i])-sum1+((sum2-sum1)-(i+1)*a[i])
                ans.append(diff)
        return ans
