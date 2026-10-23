
#include <cstring>
class Solution {
public:
    int t[2501][2501];

    int solve(vector<int>& nums, int i, int p) {
        if (i >= nums.size()) {
            return 0;
        }

        if (p != -1 && t[i][p] != -1) {
            return t[i][p];
        }

        // Skip current element
        int skip = solve(nums, i + 1, p);

        // Take current element if it maintains increasing order
        int take = 0;
        if (p == -1 || nums[i] > nums[p]) {
            take = 1 + solve(nums, i + 1, i);
        }

        int ans = max(take, skip);

        if (p != -1) {
            t[i][p] = ans;
        }

        return ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        return solve(nums, 0, -1);
    }
};
