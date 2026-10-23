class Solution {
public:
    int t[1001][1001];

    int solve(int i, vector<int>& nums, int p) {

        if(i >= nums.size()) {
            return 0;
        }

        if(t[i][p + 1] != -1) {
            return t[i][p + 1];
        }

        int take = 0;

        if(p == -1 || nums[i] > nums[p]) {
            take = 1 + solve(i + 1, nums, i);
        }

        int skip = solve(i + 1, nums, p);

        return t[i][p + 1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {

        fill(&t[0][0], &t[0][0] + 1001 * 1001, -1);

        return solve(0, nums, -1);
    }
};