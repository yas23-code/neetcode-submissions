class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int> t(n + 1, 0);

        // Case 1: Skip last house
        // Consider houses [0 ... n-2]

        t[0] = 0;
        t[1] = nums[0];

        for(int i = 2; i < n; i++) {

            int take = nums[i - 1] + t[i - 2];
            int skip = t[i - 1];

            t[i] = max(take, skip);
        }

        int result1 = t[n - 1];


        // Case 2: Skip first house
        // Consider houses [1 ... n-1]

        t = vector<int>(n + 1, 0);

        t[1] = nums[1];

        for(int i = 2; i <= n - 1; i++) {

            int take = nums[i] + t[i - 2];
            int skip = t[i - 1];

            t[i] = max(take, skip);
        }

        int result2 = t[n - 1];

        return max(result1, result2);
    }
};