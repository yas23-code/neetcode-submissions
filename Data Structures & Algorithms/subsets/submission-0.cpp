class Solution {
public:

    void getAllSet(vector<int>& nums,
                   vector<int>& ans,
                   int i,
                   vector<vector<int>>& allSubSet) {

        if (i == nums.size()) {
            allSubSet.push_back(ans);
            return;
        }

        // Include
        ans.push_back(nums[i]);
        getAllSet(nums, ans, i + 1, allSubSet);

        // Backtrack
        ans.pop_back();

        // Exclude
        getAllSet(nums, ans, i + 1, allSubSet);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> allSubSet;
        vector<int> ans;

        getAllSet(nums, ans, 0, allSubSet);

        return allSubSet;
    }
};