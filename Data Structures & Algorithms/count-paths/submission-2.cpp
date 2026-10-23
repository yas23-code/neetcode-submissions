#include <cstring>

class Solution {
public:
    int t[101][101];

    int solve(int i, int j, int m, int n) {

        // Outside the grid
        if(i >= m || j >= n) {
            return 0;
        }

        // Reached destination
        if(i == m - 1 && j == n - 1) {
            return 1;
        }

        // Already calculated
        if(t[i][j] != -1) {
            return t[i][j];
        }

        // Move right
        int right = solve(i, j + 1, m, n);

        // Move down
        int down = solve(i + 1, j, m, n);

        return t[i][j] = right + down;
    }

    int uniquePaths(int m, int n) {

        memset(t, -1, sizeof(t));

        return solve(0, 0, m, n);
    }
};