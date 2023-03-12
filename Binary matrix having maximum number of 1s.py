class Solution:
    def findMaxRow(self, mat, N):
        # Code here
        j = n-1
        ind = 0
        for i in range(N):
            while j >= 0 and mat[i][j] == 1:
                j-=1
                ind = i
        return [ind, n - j - 1]
