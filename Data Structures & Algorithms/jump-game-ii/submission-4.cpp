class Solution {
public:
    int jump(vector<int>& nums) {

        if (nums.size() == 1)
            return 0;

        int totalJump = 0;
        int coverage = 0;
        int lastJumpIdx = 0;
        int destination = nums.size() - 1;

        for (int i = 0; i < nums.size(); i++) {

            coverage = max(coverage, i + nums[i]);

            if (i == lastJumpIdx) {

                lastJumpIdx = coverage;
                totalJump++;

                if (coverage >= destination) {
                    return totalJump;
                }
            }
        }

        return totalJump;
    }
};