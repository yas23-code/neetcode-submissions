#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int t[2][101][101];

    int solve(int person, int i, vector<int>& piles, int M) {
        int n = piles.size();

        // No piles left
        if (i >= n) {
            return 0;
        }

        // Already calculated
        if (t[person][i][M] != -1) {
            return t[person][i][M];
        }

        int result = (person == 1) ? -1 : INT_MAX;

        int stones = 0;

        // Take X piles
        for (int x = 1; x <= min(2 * M, n - i); x++) {

            stones += piles[i + x - 1];

            if (person == 1) {
                // Alice wants to maximize her stones
                result = max(result,
                             stones + solve(0, i + x, piles, max(M, x)));
            }
            else {
                // Bob wants to minimize Alice's stones
                result = min(result,
                             solve(1, i + x, piles, max(M, x)));
            }
        }

        return t[person][i][M] = result;
    }

    int stoneGameII(vector<int>& piles) {
        memset(t, -1, sizeof(t));

        return solve(1, 0, piles, 1);
    }
};