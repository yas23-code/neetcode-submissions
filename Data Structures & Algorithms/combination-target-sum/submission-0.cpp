class Solution {
public:

    void getAllComb(vector<int>& nums,
                    vector<int>& comb,
                    vector<vector<int>>& ans,
                    int idx,
                    int target) {

        if (target == 0) {
            ans.push_back(comb);
            return;
        }

        if (idx == nums.size() || target < 0) {
            return;
        }

        // Include current number
        comb.push_back(nums[idx]);
        getAllComb(nums, comb, ans, idx, target - nums[idx]);

        // Backtrack
        comb.pop_back();

        // Exclude current number
        getAllComb(nums, comb, ans, idx + 1, target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;
        vector<int> comb;

        getAllComb(nums, comb, ans, 0, target);

        return ans;
    }
};