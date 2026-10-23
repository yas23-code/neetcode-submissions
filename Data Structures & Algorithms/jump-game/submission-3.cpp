
#include <cstring>
class Solution {
public:
    int t[10001];

    bool solve(vector<int>& nums, int n, int idx) {
        // Reached the last index
        if (idx == n - 1) {
            return true;
        }

        // Invalid index
        if (idx >= n) {
            return false;
        }

        if (t[idx] != -1) {
            return t[idx];
        }

        for (int i = 1; i <= nums[idx]; i++) {
            if (solve(nums, n, idx + i)) {
                return t[idx] = 1;
            }
        }

        return t[idx] = 0;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        memset(t, -1, sizeof(t));

        return solve(nums, n, 0);
    }
};
