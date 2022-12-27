class Solution{
public:
    bool valid(int i, int j, int n, int m) {
        if(i >= 0 && j >= 0 && i < n && j < m)
            return true;
        return false;
    }
    
    int hopscotch(int n, int m, vector<vector<int>> mat, int ty, int i, int j)
    {
        int sum = 0;
        if(ty == 0) {
            if(j%2 == 0) {
                if(valid(i-1, j-1, n, m)) sum += mat[i-1][j-1];
                if(valid(i-1, j, n, m)) sum += mat[i-1][j];
                if(valid(i-1, j+1, n, m)) sum += mat[i-1][j+1];
                if(valid(i, j-1, n, m)) sum += mat[i][j-1];
                if(valid(i, j+1, n, m)) sum += mat[i][j+1];
                if(valid(i+1, j, n, m)) sum += mat[i+1][j];
            }
            else{
                if(valid(i-1, j, n, m)) sum += mat[i-1][j];
                if(valid(i, j-1, n, m)) sum += mat[i][j-1];
                if(valid(i, j+1, n, m)) sum += mat[i][j+1];
                if(valid(i+1, j-1, n, m)) sum += mat[i+1][j-1];
                if(valid(i+1, j, n, m)) sum += mat[i+1][j];
                if(valid(i+1, j+1, n, m)) sum += mat[i+1][j+1];
            }
        }
        else{
            if(j%2 == 0) {
                if(valid(i-2, j-1, n, m)) sum += mat[i-2][j-1]; 
                if(valid(i-2, j, n, m)) sum += mat[i-2][j];
                if(valid(i-2, j+1, n, m)) sum += mat[i-2][j+1]; 
                if(valid(i-1, j-2, n, m)) sum += mat[i-1][j-2];
                if(valid(i-1, j+2, n, m)) sum += mat[i-1][j+2]; 
                if(valid(i, j-2, n, m)) sum += mat[i][j-2];
                if(valid(i, j+2, n, m)) sum += mat[i][j+2]; 
                if(valid(i+1, j-2, n, m)) sum += mat[i+1][j-2];
                if(valid(i+1, j-1, n, m)) sum += mat[i+1][j-1]; 
                if(valid(i+1, j+1, n, m)) sum += mat[i+1][j+1];
                if(valid(i+1, j+2, n, m)) sum += mat[i+1][j+2]; 
                if(valid(i+2, j, n, m)) sum += mat[i+2][j];
            }
            else{
                if(valid(i-1, j-2, n, m)) sum += mat[i-1][j-2]; 
                if(valid(i-1, j-1, n, m)) sum += mat[i-1][j-1];
                if(valid(i-2, j, n, m)) sum += mat[i-2][j]; 
                if(valid(i-1, j+1, n, m)) sum += mat[i-1][j+1];
                if(valid(i-1, j+2, n, m)) sum += mat[i-1][j+2]; 
                if(valid(i, j-2, n, m)) sum += mat[i][j-2];
                if(valid(i, j+2, n, m)) sum += mat[i][j+2]; 
                if(valid(i+1, j-2, n, m)) sum += mat[i+1][j-2];
                if(valid(i+1, j+2, n, m)) sum += mat[i+1][j+2]; 
                if(valid(i+2, j-1, n, m)) sum += mat[i+2][j-1];
                if(valid(i+2, j, n, m)) sum += mat[i+2][j]; 
                if(valid(i+2, j+1 ,n, m)) sum += mat[i+2][j+1];
            }
        }
        return sum;
    }
};
