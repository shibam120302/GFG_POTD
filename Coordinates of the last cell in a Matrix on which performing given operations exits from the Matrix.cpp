class Solution{
    public:
    bool issafe(int m, int n, int i, int j)
    {
     
      // Cases for invalid cells
      if (i < 0)
        return false;
      if (j < 0)
        return false;
      if (i >= m)
        return false;
      if (j >= n)
        return false;
     
      // Return true if valid
      return true;
    }
     
    // Function to find indices of cells
    // of a matrix from which traversal
    // leads to out of the matrix
    pair<int,int> endPoints(vector<vector<int>> arr){
     
      // Starting from cell (0, 0),
      // traverse in right direction
      int m = arr.size();
      int n = arr[0].size();
      int i = 0;
      int j = 0;
      int current_i = 0;
      int current_j = 0;
     
      char current_d = 'r';
     
      // Stores direction changes
      map<char,char> rcd = {{'l', 'u'},{'u', 'r'},
                            {'r', 'd'},
                            {'d', 'l'}};
     
      // Iterate until the current cell
      // exceeds beyond the matrix
      while (issafe(m, n, i, j)){
     
        // Current index
        current_i = i;
        current_j = j;
     
        // If the current cell is 1
        if (arr[i][j] == 1){
     
          char move_in = rcd[current_d];
     
          // Update arr[i][j] = 0
          arr[i][j] = 0;
     
          // Update indices according
          // to the direction
          if (move_in == 'u')
            i -= 1;
          else if(move_in == 'd')
            i += 1;
          else if(move_in == 'l')
            j -= 1;
          else if(move_in == 'r')
            j += 1;
     
          current_d = move_in;
     
        }
     
        // Otherwise
        else{
          // Update indices according
          // to the direction
          if (current_d == 'u')
            i -= 1;
          else if(current_d == 'd')
            i += 1;
          else if(current_d == 'l')
            j -= 1;
          else if(current_d == 'r')
            j += 1;
        }
      }
     
      // The exit cooridnates
      return {current_i, current_j};
     
    }
};
