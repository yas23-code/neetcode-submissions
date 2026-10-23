class Solution {
public:
    int calPoints(vector<string>& operations) {

        stack<int> st;
        int sum = 0;

        for(string ch : operations) {

            // Number
            if(ch != "+" && ch != "D" && ch != "C") {
                st.push(stoi(ch));
            }

            // "+"
            else if(ch == "+") {

                int first = st.top();
                st.pop();

                int second = st.top();

                st.push(first);
                st.push(first + second);
            }

            // "C"
            else if(ch == "C") {
                st.pop();
            }

            // "D"
            else if(ch == "D") {
                st.push(2 * st.top());
            }
        }

        while(!st.empty()) {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};