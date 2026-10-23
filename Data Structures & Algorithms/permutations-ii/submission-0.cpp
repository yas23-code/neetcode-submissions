class Solution {
public:

    void getAllPer(vector<int>& nums,
                   int idx,
                   vector<vector<int>>& ans) {

        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> uniqueSet;

        for (int i = idx; i < nums.size(); i++) {

            if (uniqueSet.find(nums[i]) != uniqueSet.end())
                continue;

            uniqueSet.insert(nums[i]);

            swap(nums[idx], nums[i]);

            getAllPer(nums, idx + 1, ans);

            // Backtrack
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<vector<int>> ans;

        getAllPer(nums, 0, ans);

        return ans;
    }
};