
class Solution {
public:
    bool isPali(string s) {
        string s1 = s;
        reverse(s1.begin(), s1.end());
        return s == s1;
    }

    void getAllParts(string s, vector<vector<string>>& result,
                     vector<string>& ans) {
        if (s.length() == 0) {
            result.push_back(ans);
            return;
        }

        for (int i = 0; i < s.length(); i++) {
            string part = s.substr(0, i + 1);

            if (isPali(part)) {
                // Choose
                ans.push_back(part);

                // Explore remaining string
                getAllParts(s.substr(i + 1), result, ans);

                // Backtrack
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> ans;

        getAllParts(s, result, ans);

        return result;
    }
};
