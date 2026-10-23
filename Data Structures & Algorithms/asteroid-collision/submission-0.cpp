class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids) {
            bool shouldPush = true;

            while (!st.empty()) {
                int top = st.top();

                // Equal size -> both explode
                if (top > 0 && top == -a) {
                    st.pop();
                    shouldPush = false;
                    break;
                }
                // No collision possible
                else if (top < 0 || a > 0 || top < a) {
                    break;
                }
                // Stack top destroys current asteroid
                else if (abs(top) > abs(a)) {
                    shouldPush = false;
                    break;
                }
                // Current asteroid destroys stack top
                else if (abs(top) < abs(a)) {
                    st.pop();
                }
            }

            if (shouldPush) {
                st.push(a);
            }
        }

        vector<int> res(st.size());

        for (int i = st.size() - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }

        return res;
    }
};