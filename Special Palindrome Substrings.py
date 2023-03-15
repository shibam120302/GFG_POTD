import math
INF = float("inf")

class Solution():
    def specialPalindrome(self, s1, s2):
        #your code goes here
        l1=len(s1)
        l2=len(s2)
        ans=INF
        for i in range(l1-l2+1):
    
            temp=s1[:i]+s2+s1[i+l2:]
            cost=0
            for j in range(i, i+l2):
    
                if(s1[j]!=temp[j]):
                    cost+=1
            z=0
            for j in range(math.ceil(l1/2)):    
                if((j<i or j>=i+l2) and temp[j]!=temp[l1-j-1]):
                    cost+=1
                elif(temp[j]!=temp[l1-j-1] and (l1-j-1<i or l1-j-1>=i+l2)):
                    cost+=1
                elif(temp[j]!=temp[l1-j-1]):
                    z=1
                    break

            if(z==0):
                ans=min(ans,cost)
        if(ans == INF):
          return -1
        return ans
