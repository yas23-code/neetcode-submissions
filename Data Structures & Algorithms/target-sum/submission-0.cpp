class Solution {
public:
    int s;

    int solve(vector<int>& nums, int target, int i, int currsum,
              vector<vector<int>>& t) {

        if(i == nums.size()) {
            if(currsum == target) {
                return 1;
            }
            return 0;
        }

        // currsum can be negative, so add s as an offset
        if(t[i][currsum + s] != -1) {
            return t[i][currsum + s];
        }

        // Put + before nums[i]
        int plus = solve(nums, target, i + 1,
                         currsum + nums[i], t);

        // Put - before nums[i]
        int minus = solve(nums, target, i + 1,
                          currsum - nums[i], t);

        return t[i][currsum + s] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        s = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> t(
            nums.size(),
            vector<int>(2 * s + 1, -1)
        );

        return solve(nums, target, 0, 0, t);
    }
};