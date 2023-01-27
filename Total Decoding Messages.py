class Solution:
	def CountWays(self, str):
		# Code here
		if str[0] == '0' :
				return 0
			
		n = len(str)
		mod = 1000000007
		
		dp = [0 for i in range(n+1)]
		
		dp[0] = dp[1] = 1
		
		for i in range(1,n):
		    if str[i] == '0' and str[i-1] > '2' :
		        return 0
		       
		
		for i in range(2,n+1):
			if str[i-1] > '0' :
			    dp[i] = dp[i-1]
		
			if str[i-2] == '1' or (str[i-2] == '2' and str[i-1] < '7') :
			    dp[i] +=dp[i-2]
			
			dp[i] %= mod
		
		return dp[n]
