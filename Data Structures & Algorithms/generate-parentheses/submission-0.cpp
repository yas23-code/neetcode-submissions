class Solution {
public:

    void fnc(vector<string>& ans, int n,
             int open, int close,
             string curr_str) {

        if (curr_str.length() == 2 * n) {
            ans.push_back(curr_str);
            return;
        }

        // Add '('
        if (open < n) {
            fnc(ans, n, open + 1, close, curr_str + "(");
        }

        // Add ')'
        if (close < open) {
            fnc(ans, n, open, close + 1, curr_str + ")");
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;

        fnc(ans, n, 0, 0, "");

        return ans;
    }
};