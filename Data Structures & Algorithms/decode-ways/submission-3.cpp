#include<cstring>
class Solution {
public:
    int t[101];

    int solve(string& s, int i, int n) {

        if(i == n) {
            return 1;
        }

        if(t[i] != -1) {
            return t[i];
        }

        if(s[i] == '0') {
            return t[i] = 0;
        }

        // Take one digit
        int take_first = solve(s, i + 1, n);

        // Take two digits
        int take_second = 0;

        if(i + 1 < n) {

            if(s[i] == '1' ||
               (s[i] == '2' && s[i + 1] <= '6')) {

                take_second = solve(s, i + 2, n);
            }
        }

        return t[i] = take_first + take_second;
    }

    int numDecodings(string s) {

        int n = s.length();

        memset(t, -1, sizeof(t));

        return solve(s, 0, n);
    }
};