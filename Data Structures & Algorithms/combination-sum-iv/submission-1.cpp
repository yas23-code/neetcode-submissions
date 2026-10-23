class Solution {
public:
    int t[201][1001];

    int solve(int idx, vector<int>& nums, int target) {

        if(target == 0)
            return 1;

        if(idx >= nums.size() || target < 0)
            return 0;

        if(t[idx][target] != -1)
            return t[idx][target];

        // Take current number
        int take = solve(0, nums, target - nums[idx]);

        // Don't take current number
        int reject = solve(idx + 1, nums, target);

        return t[idx][target] = take + reject;
    }

    int combinationSum4(vector<int>& nums, int target) {

        fill(&t[0][0], &t[0][0] + 201 * 1001, -1);

        return solve(0, nums, target);
    }
};