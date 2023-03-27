class Solution:
    # Function to count the number
    # of ways to divide the number N
    # in groups such that each group
    # has K number of elements
    def calculate(self, pos, prev, left, K, dp):
        
        # Base Case
        if (pos == K):
            if (left == 0):
                return 1
            else:
                return 0
    
        # If N is divides completely
        # into less than K groups
        if (left == 0):
            return 0
        if(dp[pos][left][prev]!=-1):
            return dp[pos][left][prev]
        answer = 0
    
        # Put all possible values
        # greater equal to prev
        for i in range(prev, left + 1):
            answer += self.calculate(pos + 1, i, left - i, K,dp)
           
        dp[pos][left][prev]= answer
        return answer
        
    def countWaystoDivide(self, N, K):
        dp = [[[-1 for j in range(N+1)] for j in range(N+1)] for j in range(K+1)]
        return self.calculate(0, 1, N, K, dp)
     
    

