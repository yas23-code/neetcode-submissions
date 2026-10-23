class Solution {
public:
    int t[201];
    unordered_set<string> st;

    bool solve(int i, string& s) {
        int n = s.length();

        if(i == n) {
            return true;
        }

        if(t[i] != -1) {
            return t[i];
        }

        for(int l = i; l < n; l++) {

            string temp = s.substr(i, l - i + 1);

            if(st.find(temp) != st.end()) {

                if(solve(l + 1, s)) {
                    return t[i] = true;
                }
            }
        }

        return t[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        fill(t, t + 201, -1);

        for(string &word : wordDict) {
            st.insert(word);
        }

        return solve(0, s);
    }
};