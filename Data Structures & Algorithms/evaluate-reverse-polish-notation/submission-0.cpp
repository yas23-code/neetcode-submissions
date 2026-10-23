class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string s : tokens) {

            if (s == "+" || s == "-" ||
                s == "*" || s == "/") {

                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                int res;

                if (s == "+")
                    res = b + a;
                else if (s == "-")
                    res = b - a;
                else if (s == "*")
                    res = b * a;
                else
                    res = b / a;

                st.push(res);
            }
            else {
                st.push(stoi(s));
            }
        }

        return st.top();
    }
};