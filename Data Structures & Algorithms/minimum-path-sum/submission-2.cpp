
#include <cstring>

class Solution {
public:
    int t[201][201];

    int solve(int i, int j, int m, int n,
              vector<vector<int>>& grid) {

        // Out of bounds
        if (i >= m || j >= n) {
            return INT_MAX;
        }

        // Destination reached
        if (i == m - 1 && j == n - 1) {
            return grid[i][j];
        }

        if (t[i][j] != -1) {
            return t[i][j];
        }

        int down = solve(i + 1, j, m, n, grid);
        int right = solve(i, j + 1, m, n, grid);

        return t[i][j] =
            grid[i][j] + min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        memset(t, -1, sizeof(t));

        return solve(0, 0, m, n, grid);
    }
};
