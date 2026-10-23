
#include<cstring>
class Solution {
public:
    int t[201][201];

    int solve(int i, int j, vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        if (t[i][j] != -1) {
            return t[i][j];
        }

        int directions[4][2] = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        int best = 1;

        for (auto& d : directions) {
            int ni = i + d[0];
            int nj = j + d[1];

            if (ni >= 0 && ni < m &&
                nj >= 0 && nj < n &&
                matrix[ni][nj] > matrix[i][j]) {

                best = max(best, 1 + solve(ni, nj, matrix));
            }
        }

        return t[i][j] = best;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        memset(t, -1, sizeof(t));

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, solve(i, j, matrix));
            }
        }

        return ans;
    }
};
