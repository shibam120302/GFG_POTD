class Solution:
    def dominantPairs(self,n,arr):
        left_part=arr[:n//2]#we divide arr in two parts left and right
        right_part=arr[n//2:]
        left_part.sort()#sort the left and right parts so we can efficently find suitable pairs
        right_part.sort()
        right=0
        ans=0#intialising the ans 
        
        for left in range(n//2):
            
            while right<n//2 and left_part[left]>=5*right_part[right]:
                right+=1
            ans+=right#right is the number with which left index elements forms valid pairs
        return ans
