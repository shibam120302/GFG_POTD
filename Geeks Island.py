class Solution():
    def isValid(self,r,c, n,m):
        if r>=n or r<0 or c>=m or c<0:
            return False
        return True
    def dfs(self, prev, r, c, mat, vis, n, m):
        if not self.isValid(r,c,n,m):
            return
        if vis[r][c]:
            return
        if mat[r][c] < prev:
            return
        vis[r][c]=True
        self.dfs(mat[r][c], r+1, c, mat,vis, n,m)
        self.dfs(mat[r][c], r-1, c, mat,vis, n,m)
        self.dfs(mat[r][c], r, c-1, mat,vis, n,m)
        self.dfs(mat[r][c], r, c+1, mat,vis, n,m)


    def water_flow(self, mat, n, m):
        indian = [[False for i in range(m)] for i in range(n)]
        arabian = [[False for i in range(m)] for i in range(n)]
        self.dfs(-1,0,4,mat,indian,n, m)
        for i in range(n): self.dfs(-1, i, 0, mat, indian, n, m)
        for i in range(m): self.dfs(-1, 0, i, mat, indian, n, m)
        for i in range(n): self.dfs(-1, i, m-1, mat, arabian, n, m)
        for i in range(m): self.dfs(-1, n-1, i, mat, arabian, n, m)
        ct  = 0
        for i in range(n):

            for j in range(m):
                if indian[i][j] and arabian[i][j]:
                    ct += 1
        return ct
