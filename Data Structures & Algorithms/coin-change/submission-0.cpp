class Solution {
public:

    int solve(int i, vector<int>& coins, int amount,
              vector<vector<int>>& t) {

        if(amount == 0) {
            return 0;
        }

        if(i < 0) {
            return 1e9;
        }

        if(t[i][amount] != -1) {
            return t[i][amount];
        }

        if(coins[i] > amount) {
            return t[i][amount] =
                solve(i - 1, coins, amount, t);
        }

        int keep = 1 + solve(i, coins,
                             amount - coins[i], t);

        int skip = solve(i - 1, coins, amount, t);

        return t[i][amount] = min(keep, skip);
    }

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>> t(
            n, vector<int>(amount + 1, -1)
        );

        int ans = solve(n - 1, coins, amount, t);

        if(ans == 1e9) {
            return -1;
        }

        return ans;
    }
};