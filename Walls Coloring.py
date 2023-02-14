inf = 10**18
class Solution():
    def minCost(self, colors, N):
        ans = colors[0][:]
        for i in range(1, n):
            tmp = ans[:]
            ans = [inf, inf, inf]
            for j in range(3):
                ans[j] = min(ans[j], tmp[(j+1)%3]+colors[i][j])
                ans[j] = min(ans[j], tmp[(j+2)%3]+colors[i][j])
        return min(ans)
