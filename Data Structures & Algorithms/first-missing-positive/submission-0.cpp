class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        unordered_set<int> st;

        for(int num : nums) {
            if(num > 0)
                st.insert(num);
        }

        int ans = 1;

        while(st.find(ans) != st.end()) {
            ans++;
        }

        return ans;
    }
};