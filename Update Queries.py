class Solution():
    def updateQuery(self, N, Q, U):
        bits = 5
        dp = [[0 for j in range(bits)] for i in range(n+1)]
        for i in U:
            l,r,x = i
            for j in range(bits):
                val = int(x&(1<<j) > 0)
                dp[l-1][j]+=val
                dp[r][j] -= val
        tmp = 0
        arr = [0]*n

        for j in range(bits):
                if dp[0][j] > 0:
                    val = 1
                else:
                    val = 0
                tmp += val<<j
        arr[0] = tmp

        for i in range(1, n):
            tmp = 0
            for j in range(bits):
                dp[i][j] += dp[i-1][j]
                if dp[i][j] > 0:
                    val = 1
                else:
                    val = 0
                tmp += val<<j
            arr[i] = tmp
        return arr
