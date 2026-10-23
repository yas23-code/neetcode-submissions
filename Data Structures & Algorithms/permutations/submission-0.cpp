class Solution {
public:

    void getAllPer(vector<int>& nums,
                   int idx,
                   vector<vector<int>>& ans) {

        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {

            swap(nums[idx], nums[i]);

            getAllPer(nums, idx + 1, ans);

            // Backtrack
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;

        getAllPer(nums, 0, ans);

        return ans;
    }
};