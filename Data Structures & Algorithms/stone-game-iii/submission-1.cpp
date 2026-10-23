
#include <cstring>
class Solution {
public:
    int t[50001];

    int solve(vector<int>& stoneValue, int idx, int n) {
        if (idx >= n) {
            return 0;
        }

        if (t[idx] != -1) {
            return t[idx];
        }

        // Take one stone
        int result = stoneValue[idx] - solve(stoneValue, idx + 1, n);

        // Take two stones
        if (idx + 1 < n) {
            result = max(result,
                stoneValue[idx] + stoneValue[idx + 1]
                - solve(stoneValue, idx + 2, n));
        }

        // Take three stones
        if (idx + 2 < n) {
            result = max(result,
                stoneValue[idx] + stoneValue[idx + 1]
                + stoneValue[idx + 2]
                - solve(stoneValue, idx + 3, n));
        }

        return t[idx] = result;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        memset(t, -1, sizeof(t));

        int result = solve(stoneValue, 0, n);

        if (result > 0) {
            return "Alice";
        } else if (result < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
    }
};
