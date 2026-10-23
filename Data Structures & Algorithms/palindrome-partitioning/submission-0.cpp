class Solution {
public:

    bool isPali(string s) {

        string s2 = s;
        reverse(s2.begin(), s2.end());

        return s == s2;
    }

    void getAllParts(string s,
                     vector<string>& partions,
                     vector<vector<string>>& ans) {

        if (s.size() == 0) {
            ans.push_back(partions);
            return;
        }

        for (int i = 0; i < s.size(); i++) {

            string part = s.substr(0, i + 1);

            if (isPali(part)) {

                partions.push_back(part);

                getAllParts(s.substr(i + 1), partions, ans);

                // Backtracking
                partions.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> partions;

        getAllParts(s, partions, ans);

        return ans;
    }
};