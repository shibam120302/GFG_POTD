class Solution:
    def uniquePaths(self, n, m, grid):
        
        mod = 1000000007
        # create a 2D-matrix and initializing with value 0
        paths = [[0]*m for i in range(n)]
        
        # initializing the left corner if no obstacle there
        if grid[0][0] == 1:
            paths[0][0] = 1
        
        # initializing first column of the 2D matrix
        for i in range(1, n):
            
            # If not obstacle
            if grid[i][0] == 1:
                paths[i][0] = paths[i-1][0]
                
        # initializing first row of the 2D matrix
        for j in range(1, m):
            
            # If not obstacle
            if grid[0][j] == 1:
                paths[0][j] = paths[0][j-1]
                
        for i in range(1, n):
            for j in range(1, m):
    
                # If current cell is not obstacle
                if grid[i][j] == 1:
                    paths[i][j] = (paths[i-1][j] + paths[i][j-1]) % mod
    
        # returning the corner value of the matrix
        return paths[-1][-1]
