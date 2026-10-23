class Solution {
public:

    void comb(string& digits,
              int idx,
              unordered_map<char, string>& mp,
              string& temp,
              vector<string>& ans) {

        if (idx == digits.size()) {
            ans.push_back(temp);
            return;
        }

        char ch = digits[idx];
        string str = mp[ch];

        for (int i = 0; i < str.size(); i++) {

            temp.push_back(str[i]);              // Do

            comb(digits, idx + 1, mp, temp, ans); // Explore

            temp.pop_back();                     // Undo
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.length() == 0)
            return {};

        unordered_map<char, string> mp;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string> ans;
        string temp = "";

        comb(digits, 0, mp, temp, ans);

        return ans;
    }
};