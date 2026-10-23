
class Solution {
public:
    void printSubSet(vector<int>& nums, int i, int n,
                     vector<vector<int>>& ans, vector<int>& result) {
        // Base case
        if (i == n) {
            ans.push_back(result);
            return;
        }

        // Include nums[i]
        result.push_back(nums[i]);
        printSubSet(nums, i + 1, n, ans, result);

        // Backtrack
        result.pop_back();

        // Exclude nums[i]
        printSubSet(nums, i + 1, n, ans, result);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> ans;
        vector<int> result;

        printSubSet(nums, 0, n, ans, result);

        return ans;
    }
};
