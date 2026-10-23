class Solution {
public:

    int solve(int i, string &s, vector<int>& dp) {

        int n = s.length();

        if(i == n) {
            return 1;
        }

        if(s[i] == '0') {
            return 0;
        }

        // Already calculated
        if(dp[i] != -1) {
            return dp[i];
        }

        // Take one digit
        int result = solve(i + 1, s, dp);

        // Take two digits
        if(i + 1 < n) {

            if(s[i] == '1' ||
              (s[i] == '2' && s[i + 1] <= '6')) {

                result += solve(i + 2, s, dp);
            }
        }

        dp[i] = result;

        return dp[i];
    }

    int numDecodings(string s) {

        int n = s.length();

        vector<int> dp(n, -1);

        return solve(0, s, dp);
    }
};