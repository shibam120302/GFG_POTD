class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        int row = 0, i = 0, j = N - 1;
        for (; i < N; i++) {
            while (mat[i][j] == 1 && j >= 0) {
                row = i;
                j--;
            }
        }
        return {row, N - 1 - j}; 
    }
};
