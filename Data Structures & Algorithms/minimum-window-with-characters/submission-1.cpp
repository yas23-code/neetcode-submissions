class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;

        // Count characters required from t
        for(char ch : t) {
            mp[ch]++;
        }

        int requiredCount = t.size();
        int left = 0;
        int right = 0;

        int minSize = INT_MAX;
        int startIndex = 0;

        while(right < s.size()) {

            // Add s[right] to the window
            if(mp[s[right]] > 0) {
                requiredCount--;
            }

            mp[s[right]]--;

            // Current window contains all characters of t
            while(requiredCount == 0) {

                int currSize = right - left + 1;

                if(currSize < minSize) {
                    minSize = currSize;
                    startIndex = left;
                }

                // Remove s[left] from window
                mp[s[left]]++;

                if(mp[s[left]] > 0) {
                    requiredCount++;
                }

                left++;
            }

            right++;
        }

        if(minSize == INT_MAX) {
            return "";
        }

        return s.substr(startIndex, minSize);
    }
};