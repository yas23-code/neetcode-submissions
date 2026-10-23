class Solution {
public:
    int expand(string s, int left, int right) {
        int count = 0;

        while(left >= 0 && right < s.length() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }

        return count;
    }

    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;

        for(int i = 0; i < n; i++) {

            // Odd length palindromes
            count += expand(s, i, i);

            // Even length palindromes
            count += expand(s, i, i + 1);
        }

        return count;
    }
};