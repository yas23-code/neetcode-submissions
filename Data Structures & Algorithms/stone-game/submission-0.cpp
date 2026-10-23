#include <cstring>
#include <numeric>

class Solution {
public:
    int t[501][501];

    int solve(int i, int j, vector<int>& piles) {

        // No piles left
        if(i > j) {
            return 0;
        }

        // Only one pile left
        if(i == j) {
            return piles[i];
        }

        // Already calculated
        if(t[i][j] != -1) {
            return t[i][j];
        }

        // Alice takes left pile
        int take_i = piles[i] +
            min(
                solve(i + 2, j, piles),
                solve(i + 1, j - 1, piles)
            );

        // Alice takes right pile
        int take_j = piles[j] +
            min(
                solve(i + 1, j - 1, piles),
                solve(i, j - 2, piles)
            );

        return t[i][j] = max(take_i, take_j);
    }

    bool stoneGame(vector<int>& piles) {

        int n = piles.size();

        memset(t, -1, sizeof(t));

        int sum = accumulate(piles.begin(), piles.end(), 0);

        int alice_score = solve(0, n - 1, piles);

        return alice_score > sum / 2;
    }
};