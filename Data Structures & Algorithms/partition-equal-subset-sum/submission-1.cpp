class Solution {
public:
    int t[101][5001];

    bool solve(int i, int x, vector<int>& nums) {

        if(x == 0) {
            return true;
        }

        if(i >= nums.size()) {
            return false;
        }

        if(t[i][x] != -1) {
            return t[i][x];
        }

        bool take = false;

        if(x >= nums[i]) {
            take = solve(i + 1, x - nums[i], nums);
        }

        bool notTake = solve(i + 1, x, nums);

        return t[i][x] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int sum = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if(sum % 2 != 0) {
            return false;
        }

        int x = sum / 2;

        fill(&t[0][0], &t[0][0] + 101 * 5001, -1);

        return solve(0, x, nums);
    }
};