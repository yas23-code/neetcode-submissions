class Solution {
public:

    void getAllSub(vector<int>& nums,
                   vector<int>& ans,
                   int i,
                   vector<vector<int>>& allSub) {

        if (i == nums.size()) {
            allSub.push_back(ans);
            return;
        }

        // Include
        ans.push_back(nums[i]);
        getAllSub(nums, ans, i + 1, allSub);

        // Backtrack
        ans.pop_back();

        // Skip duplicates
        int idx = i + 1;
        while (idx < nums.size() && nums[idx] == nums[idx - 1]) {
            idx++;
        }

        // Exclude
        getAllSub(nums, ans, idx, allSub);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> allSub;
        vector<int> ans;

        getAllSub(nums, ans, 0, allSub);

        return allSub;
    }
};