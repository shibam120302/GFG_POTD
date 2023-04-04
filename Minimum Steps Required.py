
import math
class Solution:
    def minSteps(self, str : str) -> int:
        # code here
        cnt=1;
        n = len(str)
        for i in range(n-1):
            if str[i]!=str[i-1]:
                cnt+=1
        
        return math.floor(cnt/2) + 1;
            
