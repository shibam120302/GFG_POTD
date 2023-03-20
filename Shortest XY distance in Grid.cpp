class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        int dist[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                dist[i][j] = 1e9;
            }
        }

        // check top and left
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 'X')
                    dist[i][j] = 0;
                else {
                    if (i > 0) dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                    if (j > 0) dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                }
            }
        }

        // check bottom and right
        for (int i = N - 1; i >= 0; i--) {
            for (int j = M - 1; j >= 0; j--) {
                if (grid[i][j] == 'X')
                    dist[i][j] = 0;
                else {
                    if (i < N - 1)
                        dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                    if (j < M - 1)
                        dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
                }
            }
        }

        int ans = 1e9;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 'Y') ans = min(ans, dist[i][j]);
            }
        }

        return ans;
    }
};
