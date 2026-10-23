
class Solution {
public:
    void printSum(vector<int>& nums, int target, int i, int n,
                  vector<vector<int>>& result, vector<int>& ans) {

        // Target achieved
        if (target == 0) {
            result.push_back(ans);
            return;
        }

        // Stop if elements are exhausted
        if (i == n || target < 0) {
            return;
        }

        // Include current element (use it again)
        ans.push_back(nums[i]);
        printSum(nums, target - nums[i], i, n, result, ans);

        // Backtrack
        ans.pop_back();

        // Exclude current element
        printSum(nums, target, i + 1, n, result, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<vector<int>> result;
        vector<int> ans;

        printSum(nums, target, 0, n, result, ans);

        return result;
    }
};
