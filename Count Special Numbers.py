class Solution:
    def countSpecialNumbers(self, N, arr):
        
        frequency = dict()
        distinctElements = set()
        maxVal = 0
        for i in arr:
            distinctElements.add(i)
            maxVal=max(i,maxVal)
            if(i in frequency):
                frequency[i]+=1
            else:
                frequency[i]=1
        
        specialNumbers = set()
        for i in distinctElements:
            for j in range(2*i,maxVal+1, i):
                if(j in distinctElements):
                    specialNumbers.add(j)
             
        ans = 0
        
        for ele in frequency.keys():
            if(frequency[ele]>1):
                ans+=frequency[ele]
            
            elif(ele in specialNumbers):
                ans+=1
        
        return ans
