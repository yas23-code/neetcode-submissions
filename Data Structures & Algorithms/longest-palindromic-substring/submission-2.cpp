class Solution {
public:

    int expand(string s, int left, int right) {

        while(left >= 0 && right < s.length() &&
              s[left] == s[right]) {

            left--;
            right++;
        }

        return right - left - 1;
    }

    string longestPalindrome(string s) {

        int n = s.length();

        int maxLength = 0;
        int start = 0;

        for(int i = 0; i < n; i++) {

            // Odd length palindrome
            int len1 = expand(s, i, i);

            // Even length palindrome
            int len2 = expand(s, i, i + 1);

            int len = max(len1, len2);

            if(len > maxLength) {

                maxLength = len;

                // Calculate starting position
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLength);
    }
};