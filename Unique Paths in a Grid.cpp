
class Solution {
  public:
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {

        int mod = (int)1e9+7;

        // create a 2D-matrix and initializing
        // with value 0
        vector<vector<int>> paths(n, vector<int>(m, 0));
         
        // Initializing the left corner if
        // no obstacle there
        if (grid[0][0] == 1)
            paths[0][0] = 1;
             
        // Initializing first column of
        // the 2D matrix
        for(int i = 1; i < n; i++)
        {
            // If not obstacle
            if (grid[i][0] == 1)
                paths[i][0] = paths[i-1][0];
        }
         
        // Initializing first row of the 2D matrix
        for(int j = 1; j < m; j++)
        {
             
            // If not obstacle
            if (grid[0][j] == 1)
                paths[0][j] = paths[0][j - 1];
        }  
          
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                 
                // If current cell is not obstacle
                if (grid[i][j] == 1)
                    paths[i][j] = (paths[i - 1][j] % mod +
                                  paths[i][j - 1] % mod) % mod;
            } 
        }
         
        // Returning the corner value
        // of the matrix
        return paths[n - 1][m-1]%mod;
    }
};
