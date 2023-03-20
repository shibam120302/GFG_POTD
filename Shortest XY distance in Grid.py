class Solution:
    def shortestXYDist(self, grid, N, M):
        dist = [[float('inf')] * M for _ in range(N)]
        
        # check top and left
        for y in range(N):
            for x in range(M):
                if grid[y][x] == 'X':
                    dist[y][x] = 0
                else:
                    if y > 0:
                        dist[y][x] = min(dist[y][x], dist[y - 1][x] + 1)
                    if x > 0:
                        dist[y][x] = min(dist[y][x], dist[y][x - 1] + 1)
        
        # check bottom and right
        for y in range(N - 1, -1, -1):
            for x in range(M - 1, -1, -1):
                if grid[y][x] == 'X':
                    dist[y][x] = 0
                else:
                    if y < N - 1:
                        dist[y][x] = min(dist[y][x], dist[y + 1][x] + 1)
                    if x < M - 1:
                        dist[y][x] = min(dist[y][x], dist[y][x + 1] + 1)
        
        # return mininum distance
        ans = 1e9
        
        for i in range(N):
            for j in range(M):
                if grid[i][j] == 'Y':
                    ans = min(ans, dist[i][j])
        
        return ans
