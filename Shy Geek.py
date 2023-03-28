class Solution:
    shop=Shop()
    def __init__(self,shop):
        self.shop=shop
    
    def find(self,n,k):
        low=0
        high=n-1
        count=0
        hm=dict()
        while(k>0):
            low=0
            while(low<=high):
                mid=(low+high)//2
                temp=0
                if (mid not in hm):
                    temp=self.shop.get(mid)
                else:
                    temp=hm[mid]
                hm[mid]=temp
                if (temp<=k):
                    low=mid+1
                else:
                    high=mid-1
            if high==-1:
                break
            count+=(k//(hm[high]))
            k-=(k//hm[high])*hm[high]
        return count
