#include <cstring>

class Solution {
public:
    vector<vector<int>> t;

    int solve(int i, int amount, vector<int>& coins) {

        if(amount == 0) {
            return 1;
        }

        if(i == coins.size()) {
            return 0;
        }

        if(t[i][amount] != -1) {
            return t[i][amount];
        }

        if(coins[i] > amount) {
            return t[i][amount] = solve(i + 1, amount, coins);
        }

        // Take current coin
        int take = solve(i, amount - coins[i], coins);

        // Skip current coin
        int skip = solve(i + 1, amount, coins);

        return t[i][amount] = take + skip;
    }

    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        t.assign(n, vector<int>(amount + 1, -1));

        return solve(0, amount, coins);
    }
};