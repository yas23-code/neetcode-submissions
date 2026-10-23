
#include <cstring>
class Solution {
public:
    int t[5001][501];

    int solve(int amount, vector<int>& coins, int i) {
        int n = coins.size();

        if (amount == 0) {
            return 1;
        }

        if (i >= n) {
            return 0;
        }

        if (t[amount][i] != -1) {
            return t[amount][i];
        }

        if (coins[i] > amount) {
            return t[amount][i] =
                solve(amount, coins, i + 1);
        }

        int take = solve(amount - coins[i], coins, i);
        int not_take = solve(amount, coins, i + 1);

        return t[amount][i] = take + not_take;
    }

    int change(int amount, vector<int>& coins) {
        memset(t, -1, sizeof(t));
        return solve(amount, coins, 0);
    }
};
