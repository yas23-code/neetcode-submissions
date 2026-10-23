class Solution {
public:
    string decodeString(string s) {
        stack<int> numSt;
        stack<string> strSt;

        int num = 0;
        string curr = "";

        for (char ch : s) {

            // Build the number (handles multi-digit numbers)
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            // Start of a new encoded substring
            else if (ch == '[') {
                numSt.push(num);
                strSt.push(curr);

                num = 0;
                curr = "";
            }

            // End of current encoded substring
            else if (ch == ']') {
                int times = numSt.top();
                numSt.pop();

                string prev = strSt.top();
                strSt.pop();

                string temp = "";
                for (int i = 0; i < times; i++) {
                    temp += curr;
                }

                curr = prev + temp;
            }

            // Normal character
            else {
                curr += ch;
            }
        }

        return curr;
    }
};